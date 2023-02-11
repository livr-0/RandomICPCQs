#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Drink { size_t salt, sugar, cost; };

bool didTurnLeft(const Drink& a, const Drink& b, const Drink& c) {
  long long int x = a.sugar - b.sugar, y = a.salt - b.salt, w = c.sugar - b.sugar, z = c.salt - b.salt;
  if (x == w && y == z) return false;
  return (x * z - y * w) >= 0;
}

bool compare(const Drink& a, const Drink& b) {
  return a.sugar < b.sugar ||
         (a.sugar == b.sugar && a.salt < b.salt) ||
         (a.sugar == b.sugar && a.salt == b.salt && a.cost < b.cost);
}

int main() {
  size_t t;
  cin >> t;
  while (t-- > 0) {
    size_t n;
    cin >> n;
    vector<Drink> hull, something;
    for (size_t i = 0; i < n; i++) {
      Drink q;
      cin >> q.sugar >> q.salt >> q.cost;
      something.push_back(q);
    }
    sort(something.begin(), something.end(), compare);
    for (size_t i = 0; i < something.size(); i++) {
      hull.push_back(something[i]);
      while (hull.size() >= 3 && didTurnLeft(hull[hull.size() - 1], hull[hull.size() - 2], hull[hull.size() - 3])) {
        Drink s = hull[hull.size() - 1];
        hull.pop_back(); hull.pop_back();
        hull.push_back(s);
      }
    }
    if (something.size() > 3) {
      for (size_t i = something.size() - 2; i > 0; i--) {
        hull.push_back(something[i]);
        while (hull.size() >= 3 && didTurnLeft(hull[hull.size() - 1], hull[hull.size() - 2], hull[hull.size() - 3])) {
          Drink s = hull[hull.size() - 1];
          hull.pop_back(); hull.pop_back();
          hull.push_back(s);
        }
      }
    }
    if (hull.size() >= 3 && didTurnLeft(hull[0], hull[hull.size() - 1], hull[hull.size() - 2])) {
          hull.pop_back();
    }
    size_t sum = 0;
    for (const Drink& s : hull) sum += s.cost;
    cout << endl << sum << endl;
  }
  return 0;
}
