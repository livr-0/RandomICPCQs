#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    vector<size_t> d(5e5+1);
    unordered_map<size_t, size_t> m;
    for (size_t i = 1; i <= 5e5; i++)
        for (size_t j = i; j <= 5e5; j += i)
            d[j]++;
    size_t t;
    cin >> t;
    while (t-- > 0) {
        size_t l, h, a = 0, w = 0;
        cin >> l >> h;
        for (; l <= h; l++) {
            size_t tW = m[l];
            if (tW == 0) {
                for (size_t i = 1; i < l; i++)
                    tW += d[i] * d[l - i];
                m[l] = tW;
            }
            if (tW > w) {
                w = tW;
                a = l;
            }
        }
        cout << a << " " << w << endl;
    }
    return 0;
}
