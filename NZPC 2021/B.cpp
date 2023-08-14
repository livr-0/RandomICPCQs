#include <iostream>
#include <map>

using namespace std;

map<string, int> months = {
    { "January", 1 },
    { "February", 2 },
    { "March", 3 },
    { "April", 4 },
    { "May", 5 },
    { "June", 6 },
    { "July", 7 },
    { "August", 8 },
    { "September", 9 },
    { "October", 10 },
    { "November", 11 },
    { "December", 12 }
};

int main() {
    int i;
    string s;
    cin >> i >> s;
    while (i != 0) {
        int m = months[s];
        if (i == 29 && m == 2) {
            cout << "Sorry, leapling, no birthday this year." << endl;
        }
        else if (m < 9) {
            cout << "You have had your birthday." << endl;
        }
        else if (m > 9) {
            cout << "Your birthday is still to come." << endl;
        }
        else if (m == 9) {
            if (i == 11) cout << "Happy birthday!" << endl;
            else if (i < 11) cout << "You have had your birthday." << endl;
            else cout << "Your birthday is still to come." << endl;
        }
        cin >> i >> s;
    }
    return 0;
}
