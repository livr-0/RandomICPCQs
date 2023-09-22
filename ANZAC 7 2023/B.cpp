#include <bits/stdc++.h>

using namespace std;

const int NINF = -1e8;

void find(size_t num, vector<pair<size_t, bool>>& vec, int& lp) {
    for (size_t i = lp; i < vec.size(); i++) {
        if (vec[i].first == num && !vec[i].second) {
            vec[i].second = 1;
            lp = i;
            return;
        }
    }
    lp = NINF;
}

void solve() {
    size_t a, b;
    cin >> a >> b;
    vector<size_t> nums;
    vector<pair<size_t, bool>> vec;
    while (b--) {
        size_t x; cin >> x;
        vec.push_back({ x, 0 });
        nums.push_back(x);
    }
    sort(nums.begin(), nums.end());
    int lp = 0, c = 0;
    for (const auto& num : nums) {
        find(num, vec, lp);
        if (lp != NINF) c++;
        else break;
    }
    cout << a << " " << nums.size() - c << endl;
}

int main() {
    size_t n;
    cin >> n;
    while (n--) solve();
    return 0;
}
