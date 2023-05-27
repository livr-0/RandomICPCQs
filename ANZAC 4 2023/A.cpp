#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int main() {
    set<size_t> alice = { 0, 3, 4, 7, 8, 11, 12, 15, 16, 19, 20 };
    set<size_t> bob =   { 1, 2, 5, 6, 9, 10, 13, 14, 17, 18, 21 };
    size_t n; cin >> n;
    size_t A = 0, B = 0;
    bool isFinal = false;
    for (size_t i = 1; i <= n; i++) {
        string s; cin >> s;
        stringstream ss(s);
        getline(ss, s, '-');
        size_t x = stoi(s);
        getline(ss, s);
        size_t y = stoi(s);
        size_t newA, newB;
        if (!alice.count(x + y) && !bob.count(x + y)) {
            cout << "error " << i << endl;
            return 0;
        }
        if (alice.count(x + y)) {
            newA = x;
            newB = y;
        } else {
            newA = y;
            newB = x;
        }
        if (newA < A || newB < B) {
            cout << "error " << i << endl;
            return 0;
        }
        if (isFinal && (newA != A || newB != B)) {
            cout << "error " << i << endl;
            return 0;
        }
        A = newA;
        B = newB;
        if (A == 11 || B == 11) isFinal = true;
    }
    cout << "ok" << endl;
    return 0;
}
