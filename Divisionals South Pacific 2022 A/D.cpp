#include <iostream>
#include <cmath>

using namespace std;

size_t binCoeff(size_t m, size_t k) {
    if (k == 0 || m == k) return 1;
    if (k == 1 || k == m - 1) return m;
    double order = 0;
    for (size_t i = m; i >= k; i--) order += log10(i);
    for (size_t i = m - k; i > 1; i--) order -= log10(i);
    if (order >= 9) return 0;
    return binCoeff(m - 1, k - 1) + binCoeff(m - 1, k);
}

int main() {
    size_t n, r = 1;
    cin >> n;
    while (n--) {
        size_t m, k;
        cin >> m >> k;
        r *= binCoeff(m, k);
        if (!r || r > 1e9) break;
    }
    if (r && r <= 1e9) cout << r << endl;
    else cout << "BIG ENOUGH" << endl;
    return 0;
}
