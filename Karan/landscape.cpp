#include <iostream>
#include <vector>

using namespace std;

int main() {
  size_t a, b;
  cin >> a >> b;

  vector<long long> d2(a+2), d1(a+1), landscape(a);

  while (b-- > 0) {
    char c; size_t d, e;
    cin >> c >> d >> e;
    if (c == 'R') { d2[d - 1]++; d2[d]--; d2[e]--; d2[e + 1]++; }
    else if (c == 'D') { d2[d - 1]--; d2[d]++; d2[e]++; d2[e + 1]--; }
    else if (c == 'H') {
      d2[d - 1]++;
      if ((d + e) % 2 == 0) d2[(d + e) / 2] -= 2;
      else { d2[(d + e) / 2] -= 1; d2[(d + e) / 2 + 1] -= 1; }
      d2[e + 1]++;
    }
    else {
      d2[d - 1]--;
      if ((d + e) % 2 == 0) d2[(d + e) / 2] += 2;
      else { d2[(d + e) / 2] += 1; d2[(d + e) / 2 + 1] += 1; }
      d2[e + 1]--;
    }
  }

  d1[0] = d2[0]; landscape[0] = d1[0];
  for (size_t i = 1; i < a; i++) d1[i] = d1[i - 1] + d2[i];
  for (size_t i = 1; i < a; i++) landscape[i] = landscape[i - 1] + d1[i];

  for (const long long& i : landscape) cout << i << endl;
  return 0;
}
