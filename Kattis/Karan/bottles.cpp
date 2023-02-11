#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<double> poly;

double solvePolynomial(const poly& polynomial, double x) {
  double res = 0.0;
  for (size_t i = 0; i < polynomial.size(); i++) res += polynomial[i] * pow(x, i);
  return res;
}

poly squarePolynomial(const poly& polynomial) {
  poly res;
  for (size_t i = 0; i <= (polynomial.size() - 1) * 2; i++) res.push_back(0);
  for (size_t i = 0; i < polynomial.size(); i++)
    for (size_t j = 0; j < polynomial.size(); j++)
      res[i + j] += polynomial[i] * polynomial[j];
  return res;
}

poly getAntiderivative(const poly& polynomial) {
  poly antiderivative;
  antiderivative.push_back(0);
  for (size_t i = 0; i < polynomial.size(); i++) antiderivative.push_back(polynomial[i] / (i + 1));
  return antiderivative;
}

double getVolume(const poly& polynomial, const double xHigh, const double xLow) {
  return 2 * acos(0.0) * (solvePolynomial(polynomial, xHigh) - solvePolynomial(polynomial, xLow));
}

double binaryAgain(const poly& polynomial, double lBound, double hBound, double target) {
  if (abs(lBound - hBound) <= 0.001) return lBound;
  double mid = (lBound + hBound) / 2;
  if (getVolume(polynomial, mid, 0.0) < target) return binaryAgain(polynomial, mid, hBound, target);
  return binaryAgain(polynomial, lBound, mid, target);
}

int main() {
  cout << fixed; cout.precision(2);

  size_t testCase = 1, order, volumeIncrement;
  double xLow, xHigh, offsetVolume;
  poly curve, antiderivative;

  while (cin >> order) {
    curve.clear();
    for (size_t i = 0; i <= order ;i++) { double x; cin >> x; curve.push_back(x); }
    cin >> xLow >> xHigh >> volumeIncrement;

    antiderivative = getAntiderivative(squarePolynomial(curve));
    cout << "Case " << testCase++ << ": " << getVolume(antiderivative, xHigh, xLow) << endl;

    offsetVolume = getVolume(antiderivative, xLow, 0.0);
    for (size_t i = 1; i <= 8; i++) {
      double temp = binaryAgain(antiderivative, xLow, xHigh, offsetVolume + (volumeIncrement * i));
      if (temp > xHigh - 0.01) {
        if (i == 1) cout << "insufficient volume";
        break;
      }
      cout << temp - xLow << " ";
    }
    cout << endl;
  }
  return 0;
}
