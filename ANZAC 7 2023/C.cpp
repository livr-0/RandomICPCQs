#include <bits/stdc++.h>

using namespace std;

void get_octal(string s) {
    size_t r = 0;
    for (int i = 0; i < s.length(); i++)
        r += pow(8, s.length() - i - 1) * (s[i] - '0');
    cout << r << " ";
}

void get_hex(string s) {
    size_t r = 0;
    for (int i = 0; i < s.length(); i++)
        r += pow(16, s.length() - i - 1) * (s[i] - '0');
    cout << r << " ";
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    cout << n << " ";
    if (s.find("9") != string::npos || s.find("8") != string::npos) cout << 0 << " ";
    else get_octal(s);
    cout << stoi(s) << " ";
    get_hex(s);
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
    return 0;
}
