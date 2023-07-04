#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef pair<size_t, size_t> coord;

size_t r, c;
vector<vector<bool>> grid;
size_t groupsCount = 0;
map<coord, size_t> grouping;

void floodfill(size_t i, size_t j, int g = -1) {
    if (g == -1) {
        groupsCount++;
        g = groupsCount;
    }
    grouping[{ i, j }] = g;
    if (i != 0 && grid[i - 1][j] == grid[i][j] && !grouping.count({ i - 1, j })) floodfill(i - 1, j, g);
    if (i != r - 1 && grid[i + 1][j] == grid[i][j] && !grouping.count({ i + 1, j })) floodfill(i + 1, j, g);
    if (j != 0 && grid[i][j - 1] == grid[i][j] && !grouping.count({ i, j - 1 })) floodfill(i, j - 1, g);
    if (j != c - 1 && grid[i][j + 1] == grid[i][j] && !grouping.count({ i, j + 1 })) floodfill(i, j + 1, g);
}

int main() {
    cin >> r >> c;
    grid = vector<vector<bool>>(r, vector<bool>(c));
    for (size_t i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (size_t j = 0; j < c; j++)
            if (s[j] == '1')
                grid[i][j] = 1;
    }
    for (size_t i = 0; i < r; i++)
        for (size_t j = 0; j < c; j++)
            if (!grouping.count({ i, j }))
                floodfill(i, j);
    size_t n;
    cin >> n;
    while (n--) {
        size_t r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;
        cout << (grouping[{ r1, c1 }] == grouping[{ r2, c2 }] ? (grid[r1][c1] ? "decimal" : "binary") : "neither") << endl;
    }
    return 0;
}
