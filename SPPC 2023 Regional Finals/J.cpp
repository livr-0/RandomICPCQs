#include <iostream>

using namespace std;

int main() {
    size_t k, c;
    cin >> k >> c;

    string f, m, l;
    cin >> f >> m >> l;

    for (size_t i = 0; i <= k; i++) {
        size_t suffix_size = 3 * (k - i);

        if (c < f.size()) {
            cout << f[c] << endl;
            return 0;
        }
        c -= f.size();

        if (c < suffix_size) {
            cout << "SON"[c % 3] << endl;
            return 0;
        }
        c -= suffix_size;
    }

    if (c < m.size()) {
        cout << m[c] << endl;
        return 0;
    }
    c -= m.size();

    cout << l[c % l.size()] << endl;
    return 0;
}
