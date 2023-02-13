#include <iostream>

using namespace std;

int main() {
    size_t n, c = 0;
    cin >> n;
    while (n-- > 0) {
        size_t q;
        cin >> q;
        if (c == 0) c = q;
        else {
            c++;
            if (q < c) c = q;
        }
        cout << c << " ";
    }
    return 0;
}
