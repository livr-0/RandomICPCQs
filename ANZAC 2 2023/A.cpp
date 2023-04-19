#include <iostream>

using namespace std;

int main() {
    size_t n, amin, amax, bmin, bmax;
    cin >> n >> amin >> amax >> bmin >> bmax;
    size_t sum1 = 0, sum2 = 0;
    while (n--) {
        size_t m;
        cin >> m;
        sum1 += m/2;
        sum2 += m - m/2;
    }
    if (sum1 >= amin && sum1 <= amax && sum2 >= bmin && sum2 <= bmax) cout << "Yes" << endl;
    else if (sum1 >= bmin && sum1 <= bmax && sum2 >= amin && sum2 <= amax) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
