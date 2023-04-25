#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<size_t> s;
    size_t n;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        size_t x;
        cin >> x;
        s.push_back(x);
    }
    sort(s.begin(), s.end());
    size_t res = 2000001;
    for (size_t i = 0; i < n/2; i++) {
        size_t j = n - 1 - i;
        if (s[i] + s[j] < res) res = s[i] + s[j];
    }
    cout << res << endl;
    return 0;
}
