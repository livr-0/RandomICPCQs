#include <bits/stdc++.h>

using namespace std;

map<char, size_t> m = {
    { '0', 0 }, { '1', 1 }, { '2', 2 }, { '3', 3 },
    { '4', 4 }, { '5', 5 }, { '6', 6 }, { '7', 7 },
    { '8', 8 }, { '9', 9 }, { 'A', 10 }, { 'C', 11 },
    { 'D', 12 }, { 'E', 13 }, { 'F', 14 }, { 'H', 15 },
    { 'J', 16 }, { 'K', 17 }, { 'L', 18 }, { 'M', 19 },
    { 'N', 20 }, { 'P', 21 }, { 'R', 22 }, { 'T', 23 },
    { 'V', 24 }, { 'W', 25 }, { 'X', 26 }
};

map<size_t, size_t> i = {
    { 0, 2 }, { 1, 4 }, { 2, 5 }, { 3, 7 },
    { 4, 8 }, { 5, 10 }, { 6, 11 }, { 7, 13 }
};

void getVal(string c) {
    size_t res = 0, k = 7;
    for (size_t j = 0; j < 8; j++)
        res += pow(27, k--) * m[c[j]];
    cout << res << endl;
}

void s(string b) {
    string c;
    for (const char& q : b) {
        if (q == 'B') c += '8';
        else if (q == 'G') c += 'C';
        else if (q == 'I') c += '1';
        else if (q == 'O') c += '0';
        else if (q == 'Q') c += '0';
        else if (q == 'S') c += '5';
        else if (q == 'U') c += 'V';
        else if (q == 'Y') c += 'V';
        else if (q == 'Z') c += '2';
        else c += q;
    }
    size_t checkVal = 0;
    for (size_t j = 0; j < 8; j++)
        checkVal = (checkVal + (i[j] * m[c[j]] % 27)) % 27;
    if (checkVal == m[c[8]]) getVal(c);
    else cout << "Invalid" << endl;
}

void solve() {
    string a, b;
    cin >> a >> b;
    cout << a << " ";
    s(b);
}

int main() {
    size_t n;
    cin >> n;
    while (n--) solve();
    return 0;
}
