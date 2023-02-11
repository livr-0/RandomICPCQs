#include <iostream>
#include <vector>
#include <cmath>

#define eps 1e-8
#define pi (acos(0.0) * 2.0)

using namespace std;

struct sphere {
    double r, x, y, z, v;
    sphere(double aR, double aX, double aY, double aZ) {
        r = aR; x = aX; y = aY; z = aZ;
        v = 4.0 / 3.0 * pi * pow(r, 3);
    }
    double getV(double l, double h) {
        l -= z;
        h -= z;
        l = max(-r, min(r, l));
        h = max(-r, min(r, h));
        return  pi * (pow(r, 2) * (h  - l) - ((pow(h, 3) - pow(l, 3)) / 3));
    }
};

double bin(vector<sphere>& s, double t, double b, double l, double h) {
    if (abs(l - h) <= eps) return l;
    double m = (l + h) / 2;
    double v = 1e10 * (m - b);
    for (sphere& q : s) v -= q.getV(b, m);
    if (v < t) return bin(s, t, b, m, h);
    else return bin(s, t, b, l, m);
}

int main() {
    vector<sphere> h;
    double n, s, v = 1e15, l = 0.0;
    cin >> n >> s;

    while (n-- > 0) {
        double r, x, y, z;
        cin >> r >> x >> y >> z;
        h.push_back({r, x, y, z});
        v -= h.back().v;
    }

    v /= s;

    cout << fixed; cout.precision(7);
    while (s-- > 0) {
        double q = bin(h, v, l, l, 1e5);
        cout << (q - l) / 1e3 << endl;
        l = q;
    }

    return 0;
}
