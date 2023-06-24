#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    map<char, char> m = { { 'R', 'S' }, { 'B', 'K' }, { 'L', 'H' } };
    set<char> q;
    string s;
    cin >> s;
    for (size_t i = 0; i < s.size(); i++)
        if (i >= s.size() - 2) cout << m[s[i]];
        else {
            q.clear();
            q.insert(s[i]);
            q.insert(s[i + 1]);
            q.insert(s[i + 2]);
            if (q.size() == 3) {
                cout << 'C';
                i += 2;
            } else cout << m[s[i]];
        }
    cout << endl;
    return 0;
}
