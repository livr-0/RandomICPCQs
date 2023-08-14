#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    set<string> res;
    string s;
    while (cin >> s) {
        string q;
        bool hasChars = 0;
        for (const char& p : s) {
            char c = tolower(p);
            if ((c >= 'a' && c <= 'z')) {
                hasChars = 1;
                q += c;
            }
            else if (c >= '0' && c <= '9') {
                q += c;
            }
        }
        if (hasChars) res.insert(q);
    }
    for (const string& r : res) cout << r << endl;
    return 0;
}
