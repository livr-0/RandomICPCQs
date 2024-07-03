#include <iostream>
#include <vector>

using namespace std;

int main() {
    uint n, k;
    cin >> n >> k;
    k = n * n - k;

    if (n == 1) {
        if (k == 1) {
            cout << "POSSIBLE" << endl << "." << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    } else if (k < n || k > n * 2 - 2) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << "POSSIBLE" << endl;

        vector<vector<char>> grid(n, vector<char>(n, '#'));

        for (uint i = 0; i < n - 1; i++) {
            grid[i][i] = '.';
        }

        for (uint i = 0; i <= k - n; i++) {
            grid[n - 1][i] = '.';
            grid[i][n - 1] = '.';
            grid[i][i] = '#';
        }

        for (const auto& row : grid) {
            for (const auto& cell : row) {
                cout << cell;
            }
            cout << endl;
        }
    }

    return 0;
}
