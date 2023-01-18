#include <iostream>
#include <cstring>

#define LARGE_VAL 1e18

using namespace std;

long long nv[256], cs[257][257], m[256][256];

long long dp(int p, int k, int cur) {
  if (p == 256) return 0;
  if (k == 0) return LARGE_VAL;

  long long& res = m[p][k];
  if (res != -1) return res;
  res = LARGE_VAL;

  for (int i = p + 1; i <= 256; i++) {
    while (cs[cur + 1][i] - cs[cur + 1][p] < cs[cur][i] - cs[cur][p]) cur++;
    res = min(res, cs[cur][i] - cs[cur][p] + dp(i, k - 1, cur));
  }

  return res;
}

int main() {
  int d, k;
  cin >> d; cin >> k;

  memset(nv, 0, sizeof(nv));
  memset(m, -1, sizeof(m));

  while (d-- > 0) {
    size_t r, p;
    cin >> r >> p;
    nv[r] += p;
  }

  for (size_t i = 0; i < 257; i++)
    for (size_t j = 0; j < 256; j++)
      cs[i][j + 1] = cs[i][j] + (i - j) * (i - j) * nv[j];

  cout << dp(0, k, 0) << endl;
  return 0;
}
