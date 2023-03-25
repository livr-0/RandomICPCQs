#include <iostream>

using namespace std;

int main() {
    size_t d;
    string s;
    cin >> d >> s;
    bool flag = false;
    for (const char& c : s) {
        size_t q = c - 48;
        if (!flag && q < d) { cout << d; flag = 1; }
        cout << c;
    }
    if (!flag) cout << d;
    cout << endl;
    return 0;
}
