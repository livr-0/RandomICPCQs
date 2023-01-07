#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// storing polynomials as a vector of doubles
// (index = degree, value = coefficient)
typedef vector<double> poly;

// return result of substituting specified x-value in a polynomial
double solvePolynomial(const poly& polynomial, double x) {
  double res = 0.0;
  for (size_t i = 0; i < polynomial.size(); i++) res += polynomial[i] * pow(x, i);
  return res;
}

// return a root of a given polynomial
double getRootOfPolynomial(const poly& polynomial, const poly& derivative) {
  double res = 0.0, guess;
  do {
    guess = res;
    res = guess - solvePolynomial(polynomial, guess) / solvePolynomial(derivative, guess);
  } while (fabs(res - guess) >= 0.005);
  return res;
}

// return a new polynomial integrated with respect to x
poly getAntiderivative(const poly& polynomial) {
  poly antiderivative;
  antiderivative.push_back(0);
  for (size_t i = 0; i < polynomial.size(); i++) antiderivative.push_back(polynomial[i] / (i + 1));
  return antiderivative;
}

// return the square of a polynomial
poly squarePolynomial(const poly& polynomial) {
  poly res;
  for (size_t i = 0; i <= (polynomial.size() - 1) * 2; i++) res.push_back(0);
  for (size_t i = 0; i < polynomial.size(); i++)
    for (size_t j = 0; j < polynomial.size(); j++)
      res[i + j] += polynomial[i] * polynomial[j];
  return res;
}

// get the volume of the bottle
double getVolume(const poly& antiderivative, double xHigh, double xLow) {
  double area = solvePolynomial(antiderivative, xHigh) - solvePolynomial(antiderivative, xLow);
  return area * 2 * acos(0.0);
}

// find upper bound that yields specified volume given a polynomial, its derivative, and the lower bound
double getUpperBound(poly polynomial, const poly& derivative, double volume, double xLow) {
  polynomial[0] = -(volume / (2 * acos(0.0)) + solvePolynomial(polynomial, xLow));
  return getRootOfPolynomial(polynomial, derivative);
}

int main() {
  cout << fixed; cout.precision(2); // values rounded to 2 decimal places
  size_t t = 1; // stores test case index
  while (1) {
    poly polynomial, polySquared, antiderivative;
    vector<double> heightMarks;
    double xHigh, xLow, volume, lastBound = 0.0;
    size_t order, volumeIncrement;

    // get input
    cin >> order;
    for (size_t i = 0; i <= order; i++) {
      double x; cin >> x;
      polynomial.push_back(x);
    }
    cin >> xLow >> xHigh >> volumeIncrement;

    // process output
    polySquared = squarePolynomial(polynomial);
    antiderivative = getAntiderivative(polySquared);
    volume = getVolume(antiderivative, xHigh, xLow);
    while (heightMarks.size() < 8) {
      double guessVal = ((xHigh - xLow) / 8) * (heightMarks.size() + 1);
      lastBound = getUpperBound(antiderivative, polySquared, volumeIncrement, lastBound);
      if (lastBound >= ((xHigh - xLow) - 0.01)) break;
      heightMarks.push_back(lastBound);
    }

    // display output
    cout << "Case " << t++ << ": " << volume << endl;
    if (heightMarks.size() == 0) cout << "insufficient volume";
    else for (const double& h : heightMarks) cout << h << " ";
    cout << endl;
  }
  return 0;
}
