#include <iostream>
#include <vector>

using namespace std;

// prints specified polynomial for testing purposes
void printPolynomial(const vector<double>& poly) {
  for (size_t i = 0; i < poly.size(); i++) cout << poly[i] << "^" << i << " ";
  cout << endl;
}

// solve a polynomial for a specified x-value
double solvePolynomial(const vector<double>& polynomial, double x) {
  double res = 0.0;
  for (size_t i = 0; i < polynomial.size(); i++) res += polynomial[i] * pow(x, i);
  return res;
}

// return a new polynomial integrated with respect to x
vector<double> integratePolynomial(const vector<double>& polynomial) {
  vector<double> integral;
  integral.push_back(0);
  for (size_t i = 0; i < polynomial.size(); i++) integral.push_back(polynomial[i] / (i + 1));
  return integral;
}

// return the square of a polynomial
vector<double> squarePolynomial(const vector<double>& polynomial) {
  vector<double> res;
  for (size_t i = 0; i <= (polynomial.size() - 1) * 2; i++) res.push_back(0);
  for (size_t i = 0; i < polynomial.size(); i++)
    for (size_t j = 0; j < polynomial.size(); j++)
      res[i + j] += polynomial[i] * polynomial[j];
  return res;
}

// get the volume of the bottle
double getVolume(const vector<double>& polynomial, double xHigh, double xLow) {
  vector<double> integral = integratePolynomial(squarePolynomial(polynomial));
  double area = solvePolynomial(integral, xHigh) - solvePolynomial(integral, xLow);
  return area * 2 * acos(0.0);
}

int main() {
  size_t t = 1;
  while (1) {
    vector<double> polynomial;
    size_t order, inc;
    double xHigh, xLow;

    cin >> order;
    for (size_t i = 0; i <= order; i++) { double x; cin >> x; polynomial.push_back(x); }
    cin >> xLow >> xHigh >> inc;
    double volume = getVolume(polynomial, xHigh, xLow);

    cout << fixed; cout.precision(2);
    cout << "Case " << t++ << ": " << volume << endl;
  }
  return 0;
}
