#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    size_t l, h, p, e, n;
    cin >> l >> h >> p >> e >> n;
    pair<size_t, size_t> pl, ph, pp, pe;
    pl = { 0, 0 };
    ph = { 0, 0 };
    pp = { 0, 0 };
    pe = { 0, 0 };
    while (n--) {
        string s;
        cin >> s;
        char c = s[0];
        cin >> s; cin >> s;
        size_t a1, a2;
        stringstream ss(s);
        getline(ss, s, '/');
        a1 = stoi(s);
        getline(ss, s);
        a2 = stoi(s);
        if (c == 'L') {
            pl.first += a1;
            pl.second += a2;
        } else if (c == 'H') {
            ph.first += a1;
            ph.second += a2;
        } else if (c == 'E') {
            pe.first += a1;
            pe.second += a2;
        } else {
            pp.first += a1;
            pp.second += a2;
        }
    }
    size_t res = l * ((double)pl.first/pl.second) + p * ((double)pp.first/pp.second) + e * ((double)pe.first/pe.second) + h * ((double)ph.first/ph.second);
    cout << res << endl;
    return 0;
}
