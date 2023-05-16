#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<vector<int>> grid(10, vector<int>(10));
    for (int i = 9; i >= 0; i--)
        if (i % 2 == 0) for (int j = 0; j < 10; j++) {
                int x;
                cin >> x;
                grid[i][j] = x;
            }
        else for (int j = 9; j >= 0; j--) {
                int x;
                cin >> x;
                grid[i][j] = x;
            }
    vector<int> linearGrid = { 0 };
    for (const auto& a : grid) for (const auto& b : a) linearGrid.push_back(b);
    vector<size_t> pos(5, 1);
    vector<bool> skip(5, 0);
    size_t n, t = 0, w = 0;
    cin >> n;
    while (n--) {
        if (w >= 4) break;
        t++;
        if (t == 5) t = 1;
        if (pos[t] > 100) {
            n++;
            continue;
        }
        if (skip[t]) {
            skip[t] = 0;
            n++;
            continue;
        }
        size_t v;
        cin >> v;
        pos[t] += v;
        if (pos[t] > 100) w++;
        else if (linearGrid[pos[t]] == -1) skip[t] = 1;
        else if (linearGrid[pos[t]]) pos[t] = linearGrid[pos[t]];
    }
    for (size_t i = 1; i <= 4; i++)
        if (pos[i] > 100) cout << 101 << " ";
        else cout << pos[i] << " ";
    cout << endl;
    return 0;
}
