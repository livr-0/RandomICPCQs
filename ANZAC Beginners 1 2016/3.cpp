#include <iostream>
#include <cmath>

using namespace std;

int main() {
    size_t s, v1, v2;
    cin >> s >> v1 >> v2;
    for (size_t x = 0; x <= (s / v2); x++) {
        double y = ((double)s - (double)v2*(double)x) / (double)v1;
        if (floor(y) == ceil(y)) {
            cout << y << " " << x << endl;
            return 0;
        }
    }
    cout << "Impossible" << endl;
    return 0;
}
