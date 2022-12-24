#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<char, unordered_set<char>> conversions;
unordered_set<char> visitedWhileSearching;

bool canDecrypt(const char a, const char b) {
  if (a == b) return true;
  else if (conversions[a].find(b) != conversions[a].end()) return true;
  for (const char& c : conversions[a]) {
    if (visitedWhileSearching.find(c) == visitedWhileSearching.end()) {
      visitedWhileSearching.insert(c);
      if (canDecrypt(c, b)) return true;
    }
  }
  return false;
}

int main() {
  size_t m, n;
  cin >> m >> n;

  while (m-- > 0) {
    char a, b;
    cin >> a >> b;
    conversions[a].insert(b);
  }

  while (n-- > 0) {
    string s1, s2;
    cin >> s1 >> s2;

    if (s1.length() != s2.length()) {
      cout << "no" << endl;
      continue;
    }

    bool broken = false;
    for (size_t i = 0; i < s1.length(); i++) {
      visitedWhileSearching.clear();
      if (!canDecrypt(s1[i], s2[i])) {
        broken = true;
        break;
      }
    }

    cout << (broken ? "no" : "yes") << endl;
  }
  return 0;
}
