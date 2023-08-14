#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<bool> hasMail(21, 0);
    int pos;
    cin >> pos;
    hasMail[pos] = 1;
    string s;
    while (cin >> s) {
        if (s[0] == 'D') pos -= s[1] - '0';
        else pos += s[1] - '0';
        if (pos < 1 || pos > 20 || hasMail[pos]) {
            cout << "illegal" << endl;
            return 0;
        }
        hasMail[pos] = 1;
    }
    int mails = 0;
    for (int i = 1;  i <= 20; i++)
        if (!hasMail[i])
            cout << i << " ";
        else mails++;
    if (mails == 20) cout << "none";
    cout << endl;
    return 0;
}
