#include <iostream>

using namespace std;

int main() {
    int spaces, cars;
    cin >> spaces >> cars;
    string s;
    cin >> s;
    for (const char& c : s) {
        if (c == 'I') {
            if (cars < spaces) cars++;
        }
        else if (c == 'O') {
            if (cars > 0) cars--;
            else {
                cout << "Error." << endl;
                return 0;
            }
        }
    }
    cout << cars << " cars." << endl;
    return 0;
}
