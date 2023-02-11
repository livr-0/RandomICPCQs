#include <iostream>

using namespace std;

long inverse(long a, long n) {
    long t = 0, newt = 1;
    long r = n, newr = a;
    while (newr != 0) {
        long quotient = r / newr;
        long tempt = newt;
        long tempr = newr;
        newt = t - quotient * newt;
        newr = r - quotient * newr;
        t = tempt;
        r = tempr;
    }
    return t + n;
}

int main() {
    size_t cases;
    cin >> cases;
    for (size_t i = 0; i < cases; i++) {
        long n, a;
        cin >> n >> a;
        cout << inverse(a, n) << endl;
    }
}
