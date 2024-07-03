#include <iostream>
#include <cmath>
#include <set>

using namespace std;

int main() {
    uint n, s, h;
    cin >> n >> s >> h;

    multiset<uint> sizes;
    for (uint i = 0; i < n; i++) {
        uint x;
        cin >> x;
        sizes.insert(x);
    }

    for (uint i = 0; i < h; i++) {
        if (sizes.empty()) {
            break;
        }

        auto x = sizes.lower_bound(s);
        if (x == sizes.begin()) {
            break;
        }
        x--;

        s = s + ceil(sqrt(*x));
        sizes.erase(x);
    }

    cout << s << endl;

    return 0;
}
