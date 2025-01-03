#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, t, min_lim = INT_MAX;
    cin >> n >> t;

    vector<int> d(n), s(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i] >> s[i];
        if (min_lim > s[i]) {
            min_lim = s[i];
        }
    }

    double le = -min_lim + 1e-7, re = 1e7;
    while (abs(le - re) > 1e-7) {
        double mid = (re + le) / 2;
        double estimation = 0.;
        for (int i = 0; i < n; i++) {
            estimation += 1.0 * d[i] / (s[i] + mid);
        }
        if (estimation < t) {
            re = mid;
        } else {
            le = mid;
        }
    }

    cout.precision(7);
    cout << fixed << le << endl;

    return 0;
}
