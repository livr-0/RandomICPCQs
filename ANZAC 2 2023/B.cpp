#include <iostream>
#include <vector>

using namespace std;

vector<bool> mergeRows(vector<bool>& r1, vector<bool>& r2) {
    vector<bool> result(r1.size(), 0);
    for (size_t i = 0;  i < r1.size(); i++) result[i] = r1[i] && r2[i];
    return result;
}

int main() {
    size_t r, c, y;
    cin >> r >> c >> y;
    vector<vector<bool>> grid(c, vector<bool>(r, 0));
    for (size_t i = 0; i < r; i++) {
        string row;
        cin >> row;
        for (size_t j = 0; j < c; j++)
            if (row[j] == 'o')
                grid[j][i] = 1;
    }
    vector<vector<bool>> final(max(y, c - y), vector<bool>(r, 0));
    if (y >= c - y) {
        size_t leftUpper = y - (c - y);
        for (size_t j = 0; j  < leftUpper; j++) final[j] = grid[j];
        size_t lastCol = c - 1;
        for (size_t j = leftUpper; j < y; j++) final[j] = mergeRows(grid[j], grid[lastCol--]);
    } else {
        size_t leftUpper = (c - y) - y;
        for (size_t j = 0; j < leftUpper; j++) final[j] = grid[c - j - 1];
        size_t lastCol = (c - 1) - leftUpper;
        for (size_t j = leftUpper; j < c - y; j++) final[j] = mergeRows(grid[j - leftUpper], grid[lastCol--]);
    }
    for (size_t i = 0; i < r; i++) {
        for (size_t j = 0; j < max(y, c - y); j++)
            cout << (final[j][i] ? "o" : "x");
        cout << endl;
    }
    return 0;
}
