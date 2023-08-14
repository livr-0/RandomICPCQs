#include <iostream>

using namespace std;

void solve() {
    string a, b, c;
    cin >> a >> b >> c;
    for (int i = 0; i < 4; i++) {
        if (a[i] == b[i]) {
            if (b[i] != c[i]) {
                cout << "Not a set" << endl;
                return;
            }
        } else if (a[i] == c[i] || b[i] == c[i]) {
            cout << "Not a set" << endl;
            return;
        }
    }
    cout << "Set" << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
    return 0;
}
