#include <iostream>
#include <cmath>

using namespace std;

int main() {
    size_t q;
    cin >> q;

    if (q == 1) {
        cout << "no\n";
        return 0;
    }

    for (size_t i = 2; i <= sqrt(q); i++) {
        if (q % i == 0) {
            while (q % i == 0) {
                q /= i;
            }
            if (q != 1) {
                cout << "no\n";
            } else {
                cout << "yes\n";
            }
            return 0;
        }
    }
    cout << "yes\n";
}
