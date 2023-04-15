#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    for (int i = 1; i <= n; i++) dp[i][i] = 0;
    while (c--) {
        int c1, c2, d;
        cin >> c1 >> c2 >> d;
        int& m = dp[c1][c2];
        if (m == -1 || m == d) {
            m = d;
            for (int i = 1; i <= n; i++) {
                if (dp[i][c1] == -1 && dp[i][c2] != -1) {
                    if (dp[i][c2] > d) dp[i][c1] = dp[i][c2] - d;
                    else dp[c1][i] = d - dp[i][c2];
                }
                else if (dp[i][c1] != -1) {
                    if (dp[i][c2] == -1) dp[i][c2] = dp[i][c1] + d;
                    else if (dp[i][c2] != dp[i][c1] + d) {
                        cout << "wake up" << endl;
                        return 0;
                    }
                }
            }
        } else {
            cout << "wake up" << endl;
            return 0;
        }
    }
    cout << "we live in a society" << endl;
    return 0;
}
