#include <iostream>
#include <unordered_set>

using namespace std;

void solve() {
  unordered_set<size_t> stuff;
  size_t n;
  cin >> n;
  for (size_t i = 0; i < n; i++) {
    size_t x;
    cin >> x;
    stuff.insert(x);
  }
  cout << n - stuff.size() << endl;
}

int main() {
  size_t t;
  cin >> t;
  while (t-- > 0) solve();
  return 0;
}
