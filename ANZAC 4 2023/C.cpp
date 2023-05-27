#include <iostream>

using namespace std;

int main() {
    size_t carrying = 0, attended = 0;
    size_t n;
    string s;
    cin >> n >> s;
    for (size_t i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (carrying) {
                carrying--;
                attended++;
            }
        }
        else {
            attended++;
            if (carrying < 2) carrying = 2;
        }
    }
    cout << attended << endl;
    return 0;
}
