#include <iostream>
#include <vector>

using namespace std;

vector<size_t> redVals(256);
vector<vector<size_t>> computedSums;
vector<vector<long long>> memoizedVals;

long long dp(size_t k, size_t p = 0, size_t c = 0) {
  if (p == 256) return 0;
  if (k == 0) return 1e18;
  long long& res = memoizedVals[p][k];
  if (res == -1) {
    res = 1e18;
    for (size_t newP = p + 1; newP <= 256; newP++) {
      while (computedSums[c + 1][newP] - computedSums[c + 1][p] < computedSums[c][newP] - computedSums[c][p]) c++;
      res = min(res, (long long)(computedSums[c][newP] - computedSums[c][p] + dp(k - 1, newP, c)));
    }
  }
  return res;
}

int main() {
  // Initialise Vectors
  for (size_t i = 0; i <= 256; i++) {
    vector<size_t> cs(257);
    computedSums.push_back(cs);
    if (i != 256) {
      vector<long long> m(256);
      for (long long& a : m) a = -1;
      memoizedVals.push_back(m);
    }
  }

  // Get Input
  size_t d, k;
  cin >> d >> k;
  while (d-- > 0) {
    size_t r, p;
    cin >> r >> p;
    redVals[r] = p;
  }

  // Compute Sums
  for (size_t i = 0; i <= 256; i++)
    for (size_t j = 0; j < 256; j++)
      computedSums[i][j + 1] = computedSums[i][j] + (i - j) * (i - j) * redVals[j];

  cout << dp(k) << endl;
  return 0;
}
