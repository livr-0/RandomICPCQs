#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> a(3), b(3);
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a == b) {
        if (pow(a[0], 2) + pow(a[1], 2) == pow(a[2], 2)) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
