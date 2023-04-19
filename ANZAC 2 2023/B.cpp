#include <iostream>
#include <vector>

using namespace std;

vector<bool> mergeRows(vector<bool>& row1, vector<bool>& row2) {
    vector<bool> merged(row1.size(), 0);
    for (size_t i = 0; i < row1.size(); i++)
        if (row1[i] && row2[i])
            merged[i] = 1;
    return merged;
}

int main() {
    size_t r, c, y;
    cin >> r >> c >> y;
    vector<vector<bool>> grid(c, vector<bool>(r, 0));
    for (size_t i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (size_t j = 0; j < c; j++)
            if (s[j] == 'o')
                grid[j][i] = 1;
    }
    vector<vector<bool>> res(max(y, c - y), vector<bool>(r, 0));
    if (y > c - y) {
        size_t uppers = c - 2 * (c - y);
        for (size_t j = 0; j < uppers; j++) res[j] = grid[j];
        size_t lastCol = c - 1;
        for (size_t j = uppers; j < y; j++) res[j] = mergeRows(grid[uppers], grid[lastCol--]);
    } else {
        size_t uppers = c - 2 * y;
        for (size_t j = 0; j < uppers; j++) res[j] = grid[c - j - 1];
        size_t lastCol= c - uppers - 1;
        for (size_t j = 0; j < y; j++) res[uppers + j] = mergeRows(grid[j], grid[lastCol--]);
    }
    for (size_t i = 0; i < r; i++) {
        for (size_t j = 0; j < max(y, c - y); j++)
            cout << (res[j][i] ? 'o' : 'x') << " ";
        cout << endl;
    }
    return 0;
}
