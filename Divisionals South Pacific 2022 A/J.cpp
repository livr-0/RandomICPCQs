#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int main() {
    size_t n, d, w, r = 0;
    cin >> n >> d >> w;
    vector<size_t> c(n);
    multiset<size_t> s;
    for (size_t i = 0; i < n; i++) {
        size_t x;
        cin >> x;
        c[i] = x;
    }
    for (size_t i = 0; i < n; i++) {
        size_t x;
        cin >> x;
        s.insert(x);
    }
    double wt = (double)d/w;
    for (size_t i = 0; i < n; i++) {
        size_t minReqSpeed = ceil((double)c[i]/wt);
        auto j = s.lower_bound(minReqSpeed);
        if (j == s.end()) r++;
        else s.erase(j);
    }
    cout << r << endl;
    return 0;
}
