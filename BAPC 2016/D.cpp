#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

size_t tabulation(vector<size_t>& t) {
    vector<size_t> dp(t.size() + 1, 10e8);
    dp[0] = 0;
    for (size_t i = 0; i < t.size(); i++) {
        size_t ct = t[i] + 1800, cc = dp[i] + 120;
        for (size_t j = i; j < t.size(); j++) {
            if (t[j] <= ct) { cc += 20; ct += 20; }
            else { cc += t[j] - ct + 20; ct = t[j] + 20; }
            dp[j + 1] = min(dp[j + 1], cc);
        }
    }
    return dp[t.size()];
}

int main() {
    size_t n;
    cin >> n;
    vector<size_t> t;
    for (size_t i = 0; i < n; i++) {
        size_t x;
        cin >> x;
        t.push_back(x);
    }
    cout << tabulation(t) << endl;
    return 0;
}
