#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
    vector<char> alp;
    for (char c = 'A'; c <= 'Z'; c++) alp.push_back(c);
    for (char c = 'a'; c <= 'z'; c++) alp.push_back(c);
    size_t n, c;
    cin >> n >> c;
    vector<set<char>> v;
    while (n--) {
        string s;
        cin >> s;
        set<char> S;
        for (size_t i = 0;  i < c; i++) {
            if (i >= s.length()) break;
            S.insert(s[i]);
        }
        v.push_back(S);
    }
    map<size_t, size_t> m;
    for (const char& alphabet : alp) {
        size_t longestTotal = 0, currentTotal = 0;
        for (const set<char>& s : v) {
            if (s.count(alphabet) != 0) currentTotal++;
            else {
                if (longestTotal < currentTotal) longestTotal = currentTotal;
                currentTotal = 0;
            }
        }
        if (currentTotal > longestTotal) longestTotal = currentTotal;
        m[longestTotal]++;
    }
    auto& i = *(--m.end());
    cout << i.first << " " << i.second << endl;
    return 0;
}
