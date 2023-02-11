#include <iostream>
#include <cmath>

using namespace std;

int main() {
  size_t p, a, b, c, d, n;
  double l = 0.0, q = 0.0;
  cin >> p >> a >> b >> c >> d >> n;
  for (size_t i = 1; i <= n; i++) {
    double t = p * (sin(a * i + b) + cos(c * i + d) + 2);
    if (t > l) l = t;
    else if ((l - t) > q) q = l - t;
  }
  cout.precision(7); cout << fixed << q << endl;
  return 0;
}
