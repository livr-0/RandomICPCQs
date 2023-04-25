#include <bits/stdc++.h>

using namespace std;

set<pair<int, string>> jellies;

int main() {
    size_t n;
    cin >> n;
    while (n--) {
        string s;
        size_t l, w, h;
        cin >> s >> l >> w >> h;
        jellies.insert({ l * w * h, s });
    }
    size_t f = (*jellies.begin()).first, l = (*(--jellies.end())).first;
    if (f == l) cout << "No child has lost jelly." << endl;
    else cout << (*jellies.begin()).second << " has lost jelly to " << (*(--jellies.end())).second << "." << endl;
    return 0;
}
