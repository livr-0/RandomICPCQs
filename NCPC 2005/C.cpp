#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    size_t c = 0;
    for (size_t i = 0; i < s.size(); i++)
        if ((i % 3 == 0 && s[i] != 'P') ||
            (i % 3 == 1 && s[i] != 'E') ||
            (i % 3 == 2 && s[i] != 'R')) c++;
    cout << c << endl;
    return 0;
}
