#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int x, y, z = 0;
    char a, b;
    getline(cin, s);
    cin >> x >> y >> a >> b;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c != ' ') {
            z++;
            if ((z == x && c != a) || (z == y && c != b)) {
                cout << "error" << endl;
                return 0;
            }
        }
    }
    cout << "correct" << endl;
    return 0;
}
