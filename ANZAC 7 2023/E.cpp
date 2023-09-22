#include <bits/stdc++.h>

using namespace std;

void rec(size_t n, size_t& p, size_t& q) {
    if (n == 1) {
        p = 1;
        q = 1;
    } else {
        rec(n / 2, p, q);
        if (n % 2) p = p + q;
        else q = p + q;
    }
}

void solve() {
    size_t a, b;
    size_t p = 1, q = 1;
    cin >> a >> b;
    rec(b, p, q);
    cout << a << " " << p << "/" << q << endl;
}

int main() {
    size_t n;
    cin >> n;
    while(n--) solve();
    return 0;
}
