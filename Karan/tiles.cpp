#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    vector<size_t> d(5e5+1);
    unordered_map<size_t, size_t> m;
    for (size_t i = 1; i <= 5e5; i++) for (size_t j = i; j <= 5e5; j += i) d[j]++;
    for (size_t i = 2; i <= 5e5; i++) {
        size_t j = 1, k = i - 1;
        while (j < k) m[i] += 2 * d[j++] * d[k--];
        m[i] += d[j] * d[k];
    }
    size_t t; cin >> t;
    while (t-- > 0) {
        size_t l, h, a = 0; cin >> l >> h;
        for (; l <= h; l++) if (m[l] > m[a]) a = l;
        cout << a << " " << m[a] << endl;
    }
    return 0;
}
