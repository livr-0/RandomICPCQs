#include <iostream>
#include <cmath>

#define STUFF 4.0/3 * acos(-1)
#define epsilon 1e-8

using namespace std;

size_t n, t, v, d;
double V = STUFF, l = 0;

double drawTime(double r) { return r * l / d; }
double blowTime(double r) { return (STUFF * pow(r, 3) - STUFF) / v; }

double binarySearch(double minR, double maxR) {
    if (abs(minR - maxR) <= epsilon) return minR;
    double mid = (minR + maxR) / 2;
    if (t - blowTime(mid) > drawTime(mid)) return binarySearch(mid, maxR);
    else return binarySearch(minR, mid);
}

int main() {
    cin >> n >> t >> v >> d;

    double lX = 0, lY = 0, lZ = 0;
    while (n-- > 0) {
        double x, y, z;
        int s;
        cin >> x >> y >> s;
        if (pow(x, 2) + pow(y, 2) >= 1) z = 0;
        else z = s * sqrt(1 - pow(x, 2) - pow(y, 2));
        if (!(lX == 0 && lY == 0 && lZ == 0)) l += acos(lX * x + lY * y + lZ * z);
        lX = x; lY = y; lZ = z;
    }

    cout.precision(7); cout << fixed;
    cout << binarySearch(1, cbrt((STUFF + v * t) / STUFF)) * l << endl;

    return 0;
}
