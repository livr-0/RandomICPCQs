#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    string n, a, b, r = "";
    cin >> n >> a >> b;
    reverse(n.begin(), n.end());
    unordered_map<char, size_t> l1;
    unordered_map<size_t, char> l2;
    for (size_t i = 0; i < a.size(); i++)
        l1[a[i]] = i;
    for (size_t i = 0; i < b.size(); i++)
        l2[i] = b[i];
    size_t t = 0;
    for (size_t i = 0; i < n.size(); i++)
        t += pow(a.size(), i) * l1[n[i]];
    size_t maxPower = log(t)/log(b.size());
    for (long long i = maxPower; i >= 0; i--) {
        size_t e = pow(b.size(), i);
        size_t v = t/e;
        r += l2[v];
        t -= v * e;
    }
    cout << r;
}

int main() {
    size_t t;
    cin >> t;
    for (size_t i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
    return 0;
}
