#include <iostream>
#include <vector>

using namespace std;
using ull = unsigned long long;
const ull modulo = 123456789;

int main() {
    ull l, s;
    cin >> l >> s;
    vector<ull> table(l, 0);
    table[0] = 1;
    table[1] = 1;

    for (ull i = 2; i < l; i++) {
        if (i <= s) {
            table[i] = table[i - 1] * 2 % modulo;
        }
        else {
            table[i] = (table[i - 1] * 2 - table[i - s - 1] + modulo) % modulo;
        }
    }

    ull ans = table[l - 1];
    for (ull i = 2; i <= ((l > s) ? s : l); i++) {
        ans += table[l - i] * i % modulo;
    }

    cout << ans % modulo << endl;

    return 0;
}
