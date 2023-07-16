#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> result;

void solve(int n) {
    if (n == 1) {
        result = { { 1 } };
    } else {
        solve(n - 1);
        vector<vector<int>> newResult;
        for (int i = 0; i < result.size(); i++) {
            if (i % 2 == 0) {
                for (int j = n - 1; j >= 0; j--) {
                    vector<int> row = result[i];
                    row.insert(row.begin() + j, n);
                    newResult.push_back(row);
                }
            } else {
                for (int j = 0; j < n; j++) {
                    vector<int> row = result[i];
                    row.insert(row.begin() + j, n);
                    newResult.push_back(row);
                }
            }
        }
        result = newResult;
    }
}

int main() {
    int n;
    cin >> n;
    solve(n);
    for (const vector<int>& row : result) {
        for (const int& col : row)
            cout << col << " ";
        cout << endl;
    }
    return 0;
}
