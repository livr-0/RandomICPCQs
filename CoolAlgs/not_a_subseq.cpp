// FINDS THE SHORTEST SUBSEQUENCE NOT PRESENT IN A STRING

#include <iostream>
#include <unordered_set>

using namespace std;

string getS(const string &s) {
    string r;
    unordered_set<char> c;
    for (int i = 0; i < s.length(); i++) {
        c.insert(s[i]);
        if (c.size() == 2) {
            r.push_back(s[i]);
            c.clear();
        }
    }
    for (char ch = '0'; ch <= '1'; ch++) {
        if (c.count(ch) == 0) {
            r.push_back(ch);
            return r;
        }
    }
    return r;
}

int main() {
    while (1) {
        string s; cin >> s;
        cout << getS(s) << endl;
    }
    return 0;
}
