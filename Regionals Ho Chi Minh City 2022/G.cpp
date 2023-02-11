#include <iostream>

using namespace std;

int main() {
    int n, r, x1, x2;
    cin >> n >> r >> x1 >> x2;
    while (n-- > 0) {
        int x;
        cin >> x;
        if (((x1 > x2) && (x - r >= x1)) || ((x1 < x2) && (x + r <= x1))) {
            cout << "GOAL" << endl;
            return 0;
        }
    }
    cout << "NO GOAL" << endl;
    return 0;
}
