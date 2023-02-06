#include <iostream>
#include <vector>

using namespace std;

vector<size_t> d(5e5+1);

void genD() {
    for (size_t i = 1; i <= 5e5; i++)
        for (size_t j = i; j <= 5e5; j += i)
            d[j]++;
}

void solve() {
    size_t l, h, a = 0, w = 0;
    cin >> l >> h;
    for (; l <= h; l++) {
        size_t tW = 0;
        for (size_t i = 1; i < l; i++)
            tW += d[i] * d[l - i];
        if (tW > w) {
            w = tW;
            a = l;
        }
    }
    cout << a << " " << w << endl;
}

int main() {
    genD();
    size_t t;
    cin >> t;
    while (t-- > 0) solve();
    return 0;
}
