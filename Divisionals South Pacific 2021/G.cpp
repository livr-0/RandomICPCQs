#include <iostream>

using namespace std;

bool isVowel(char c) { return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'); }
bool isGood(char c) { return (c == 'G' || c == 'L'); }

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (i == 0 && isVowel(c)) {
            cout << "no" << endl;
            return 0;
        }
        if (isVowel(c) && !isGood(s[i-1])) {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    return 0;
}
