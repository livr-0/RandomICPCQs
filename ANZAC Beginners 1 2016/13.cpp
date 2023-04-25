#include <bits/stdc++.h>

using namespace std;

int main() {
    set<pair<int, char>> se;
    unordered_map<char, int> um;
    string s;
    getline(cin, s);
    for (const char& c : s) {
        if (c == 'A' || c == 'a') um['a']++;
        else if (c == 'E' || c == 'e') um['e']++;
        else if (c == 'I' || c == 'i') um['i']++;
        else if (c == 'O' || c == 'o') um['o']++;
        else if (c == 'U' || c == 'u') um['u']++;
    }
    se.insert({um['a']*-1, 'a'});
    se.insert({um['e']*-1, 'e'});
    se.insert({um['i']*-1, 'i'});
    se.insert({um['o']*-1, 'o'});
    se.insert({um['u']*-1, 'u'});
    for (const auto& a : se) cout << a.second << ":" << a.first*-1 << " ";
    cout << endl;
    return 0;
}
