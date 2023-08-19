#include <iostream>
#include <map>

using namespace std;

int main() {
    bool ip = 0, tc = 0;
    string s, q = "", temp = "";
    cin >> s;
    int counter = 0;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (ip) {
            if (c == ')') {
                while (--counter) {
                    q += temp;
                }
                ip = 0;
                temp = "";
                counter = 0;
                continue;
            } else temp += c;
        }
        if (tc) {
            if (c >= '0' && c <= '9') {
                counter *= 10;
                counter += c - '0';
            } else {
                tc = 0;
                if (c == '(') {
                    ip = 1;
                } else {
                    while (counter--) {
                        q += c;
                    }
                    counter = 0;
                }
            }
            continue;
        }
        if (c >= '0' && c <= '9') {
            counter = c - '0';
            tc = 1;
            continue;
        }
        q += c;
    }
    cout << q << endl;
    map<char, int> m;
    for (const char& c : q) {
        m[c]++;
    }
    cout << m['S'] << " " << m['T'] << " " << m['R'] << " " << m['L'] << endl;
    return 0;
}
