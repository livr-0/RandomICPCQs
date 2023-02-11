#include <iostream>
#include <vector>

using namespace std;

void solve() {
  size_t n, m, c;
  cin >> m >> n >> c;
  vector<vector<size_t>> stuff(n, vector<size_t>(m, 0));
  int q = 1, x = 0, y = 0;
  for (size_t i = 1; i <= c; i++) {
    size_t t;
    cin >> t;
    for (size_t j = 0; j < t; j++) {
      stuff[x][y] = i;
      if (y == m - 1 && q == 1) { q = -1; x++; }
      else if (y == 0 && q == -1) { q = 1; x++; }
      else { y += q; }
    }
  }
  for (const auto& s : stuff) {
    for (const size_t& c : s) cout << c << " ";
    cout  << endl;
  }
}

int main() {
  size_t t;
  cin >> t;
  while (t-- > 0) solve();
  return 0;
}
