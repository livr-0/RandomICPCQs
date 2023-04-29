#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

size_t side;
vector<string> grid;

void printDiamond(int offset) {
    if (offset == side/2) {
        cout << grid[side/2][side/2] << endl;
        return;
    }
    int c = offset;
    for (int r = side/2; r >= offset; r--) {
        cout << grid[r][c++];
    }
    for (int r = offset + 1; r <= side/2; r++) {
        cout << grid[r][c++];
    }
    c = side - 1 - offset;
    for (int r = side / 2 + 1; r < side - offset; r++) {
        cout << grid[r][--c];
    }
    for (int r = side - offset - 2; r > side/2; r--) {
        cout << grid[r][--c];
    }
}

int main() {
    string s;
    cin >> s;
    side = sqrt(s.length());
    grid = vector<string>(side, "");
    for (size_t i = 0; i < s.length(); i++) grid[i / side] += s[i];
    for (size_t i = 0; i <= side/2; i++) printDiamond(i);
    return 0;
}
