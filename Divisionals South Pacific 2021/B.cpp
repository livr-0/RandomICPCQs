#include <iostream>
#include <set>

using namespace std;

int main() {
    multiset<size_t> t;
    size_t l, n;
    cin >> l >> n;
    while (n--) {
        size_t q;
        cin >> q;
        t.insert(q);
    }
    size_t runningTotal = 0;
    size_t c = 0;
    bool printed = 0;
    for (const size_t& q : t) {
        if (runningTotal + q > l) {
            printed = 1;
            cout << c << endl;
            break;
        } else {
            runningTotal += q;
            c++;
        }
    }
    if (!printed) cout << c << endl;
    return 0;
}
