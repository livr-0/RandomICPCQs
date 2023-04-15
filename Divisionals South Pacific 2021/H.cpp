#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> grid;

int r, c, n, m;

bool rugFits(int row, int col, bool b = 0) {
    if (!b) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j ++)
                if (grid[row+i][col+j])
                    return false;
        return true;
    }
    else {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[row+i][col+j])
                    return false;
        return true;
    }
}

int main() {
    int res = 0;
    cin >> r >> c >> n >> m;
    if (r * c < n * m) {
        cout << 0 << endl;
        return 0;
    }
    grid = vector<vector<bool>>(r, vector<bool>(c, false));
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++)
            if (s[j] == 'A')
                grid[i][j] = true;
    }
    for (int i = 0; i <= r - n; i++)
        for (int j = 0; j <= c - m; j++)
            if (rugFits(i, j))
                res++;
    if (n != m)
        for (int i = 0; i <= r - m; i++)
            for (int j = 0; j <= c - n; j++)
                if (rugFits(i, j, 1))
                    res++;
    cout << res << endl;
    return 0;
}
