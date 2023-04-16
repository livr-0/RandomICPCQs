#include <iostream>
#include <vector>

using namespace std;

void printRecursively(vector<vector<long long int>>& upos, long long int myRow, long long int myCol, long long int x, long long int c) {
    if (myRow > 0) printRecursively(upos, myRow - 1, upos[myRow][myCol], x, c);
    for (long long int i = 0; i < c; i++)
        if (i >= myCol && i < myCol + x) cout << "X";
        else cout << ".";
    cout << endl;
}

int main() {
    long long int r, c, x;
    cin >> r >> c >> x;
    vector<vector<long long int>> grid(r, vector<long long int>(c, 0));
    vector<vector<long long int>> sums(r, vector<long long int>(c - x + 1, 0));
    vector<vector<long long int>> upos(r, vector<long long int>(c - x + 1, 0));
    for (long long int i = 0; i < r; i++)
        for (long long int j = 0; j < c; j++) {
            long long int v;
            cin >> v;
            grid[i][j] = v;
        }
    for (long long int i = 0; i < r; i++)
        for (long long int j = 0; j < c - x + 1; j++)
            for (long long int k = 0; k < x; k++)
                sums[i][j] += grid[i][j+k];
    for (long long int i = 1; i < r; i++)
        for (long long int j = 0; j < c - x + 1; j++) {
            long long int maxVal = 0;
            for (long long int k = max(j - x + 1, (long long int)(0)); k <= min(j + x - 1, c - x); k++)
                if (sums[i-1][k] > maxVal) {
                    maxVal = sums[i-1][k];
                    upos[i][j] = k;
                }
            sums[i][j] += maxVal;
        }
    long long int maxVal = 0, startPos;
    for (long long int i = 0; i < c - x + 1; i++)
        if (sums[r-1][i] > maxVal) {
            maxVal = sums[r-1][i];
            startPos = i;
        }
    printRecursively(upos, r-1, startPos, x, c);
    return 0;
}
