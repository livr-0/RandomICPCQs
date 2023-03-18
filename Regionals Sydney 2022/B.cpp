#include <iostream>
#include <cmath>

using namespace std;

int main() {
    size_t n;
    cin >> n;

    int netPosTastiness = 0, netNegTastiness = 0, leastTasty = INT_MAX, mostTasty = INT_MIN;

    while (n--) {
        int tVal;
        cin >> tVal;

        if (tVal > 0) netPosTastiness += tVal;
        else netNegTastiness += tVal;

        if (mostTasty < tVal) mostTasty = tVal;
        if (leastTasty > tVal) leastTasty = tVal;
    }

    if (netNegTastiness == 0) cout << netPosTastiness - (leastTasty * 2) << endl;
    else if (netPosTastiness == 0) cout << abs(netNegTastiness - (mostTasty * 2)) << endl;
    else cout << netPosTastiness - netNegTastiness << endl;

    return 0;
}
