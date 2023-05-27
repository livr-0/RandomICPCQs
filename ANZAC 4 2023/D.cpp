#include <cmath>
#include <climits>
#include <iostream>

using namespace std;

int main() {
    size_t r;
    cin >> r;

    size_t md = INT_MAX, mx = 0, my = 0;
    for (size_t x = 0; x <= r; x++) {
        size_t y = floor(1 + sqrt(r * r - x * x));
        double d = sqrt(x * x + y * y);
        if (d < md) {
            md = d;
            mx = x;
            my = y;
        }
    }

    cout << mx << ' ' << my << endl;
}