#include <iostream>

using namespace std;

int main() {
    int n, k, t, c = 1;
    cin >> n >> k;
    t = k;
    while (n-- > 0) {
        size_t v;
        cin >> v;
        if (t >= v) t -= v;
        else { c++; t = k - v; }
    }
    cout << c << endl;
    return 0;
}
