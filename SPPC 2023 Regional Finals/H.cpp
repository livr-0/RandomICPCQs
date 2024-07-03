#include <iostream>
#include <vector>

using namespace std;

int main() {
    uint n;
    cin >> n;

    vector<uint> s(n), m(n);
    vector<double> c(n), b(n);
    for (uint i = 0; i < n; i++) { cin >> s[i]; }
    for (uint i = 0; i < n; i++) { cin >> c[i]; }
    for (uint i = 0; i < n; i++) { cin >> m[i]; }
    for (int i = n - 1; i >= 0; i--) {
        uint next_i = m[i] + i + 1;

        double value_if_accepted = s[i] * c[i];
        double value_if_rejected = next_i >= n ? 0 : b[next_i] * (1 - c[i]);
        double value_if_offered = value_if_accepted + value_if_rejected;

        double value_if_skipped = i == n - 1 ? 0 : b[i + 1];

        b[i] = max(value_if_offered, value_if_skipped);
    }

    cout.precision(7);
    cout << fixed << b[0] << endl;

    return 0;
}
