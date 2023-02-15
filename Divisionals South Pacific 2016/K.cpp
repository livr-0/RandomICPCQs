#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;


struct C {
    bool u, l, d, r;
    C() { u = 0; l = 0; d = 0; r = 0; }
};

void floodfill(size_t r, size_t c, const vector<vector<C>>& m, set<pair<size_t, size_t>>& v) {
    if (v.find({r, c}) == v.end()) {
        v.insert({r, c});
        if (m[r][c].u) floodfill(r - 1, c, m, v);
        if (m[r][c].d) floodfill(r + 1, c, m, v);
        if (m[r][c].l) floodfill(r, c - 1, m, v);
        if (m[r][c].r) floodfill(r, c + 1, m, v);
    }
}

bool checkG(const vector<vector<size_t>>& g) {
    // check row, columns
    for (size_t i = 0; i < 9; i++) {
        unordered_set<size_t> s1, s2;
        for (size_t j = 0; j < 9; j++) {
            s1.insert(g[i][j]);
            s2.insert(g[j][i]);
        }
        if (s1.size() != 9 || s2.size() != 9) return false;
    }
    // check major subsections
    for (size_t i = 0; i < 9; i++) {
        size_t r, c = (i % 3) * 3;
        if (i <= 2) r = 0;
        else if (i <= 5) r = 3;
        else r = 6;
        unordered_set<size_t> s;
        for (size_t j = r; j < r + 3; j++)
            for (size_t k = c; k < c + 3; k++)
                s.insert(g[j][k]);
        if (s.size() != 9) return false;
    }
    return true;
}

int main() {
    vector<vector<size_t>> g(9, vector<size_t>(9)); // store grid values
    vector<vector<C>> m(9, vector<C>(9, C())); // store transit possibilities

    string l;
    for (size_t i = 0; i < 9; i++) {
        // up/down boundary detection
        getline(cin, l);
        for (size_t j = 1; j < 36; j += 4) {
            if (l[j] != '-') {
                m[i][j / 4].u = 1;
                if (i != 0) m[i - 1][j / 4].d = 1;
            }
        }
        // left/right boundary detection
        getline(cin, l);
        for (size_t j = 0; j <= 32; j += 4) {
            if (l[j] != '|') {
                m[i][j / 4].l = 1;
                if (j != 0) m[i][(j / 4) - 1].r = 1;
            }
        }
        // get values
        stringstream ss(l);
        size_t j = 0; char t;
        while (ss >> t) if(isdigit(t)) g[i][j++] = t - 48;
    }
    getline(cin, l); // ignore last line of board input

    if (checkG(g)) {
        size_t r, c, s;
        while (cin >> r >> c >> s) {
            r--; c--;
            set<pair<size_t, size_t>> q;
            unordered_set<size_t> u;
            size_t w = 0;
            floodfill(r, c, m, q);
            for (const auto& t : q) {
                u.insert(g[t.first][t.second]);
                w += g[t.first][t.second];
            }
            if (w != s || q.size() != u.size()) {
                cout << "NotOK" << endl;
                return 0;
            }
        }
        cout << "OK" << endl;
    }
    else cout << "NotOK" << endl;
    return 0;
}
