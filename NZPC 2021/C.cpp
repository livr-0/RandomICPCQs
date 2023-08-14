#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    while (b != 0) {
        double x = (c - a) / b;
        if (floor(x) == ceil(x)) cout << "Term " << (int)(x + 1) << endl;
        else cout << "Not in sequence" << endl;
        cin >> a >> b >> c;
    }
    return 0;
}
