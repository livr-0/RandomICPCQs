#include <iostream>

using namespace std;

int main() {
    int n, s, max = 0;
    cin >> n >> s;

    for (size_t i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a > max) max = a;
    }

    cout << (max * s + 999) / 1000 << endl;
}
