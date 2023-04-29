#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    size_t n = 5;
    vector<size_t> v1, v2;
    for (size_t i = 0; i < n; i++) {
        size_t x;
        cin >> x;
        v1.push_back(x);
    }
    for (size_t i = 0; i < n; i++) {
        size_t x;
        cin >> x;
        v2.push_back(x);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    size_t c = 0;
    for (size_t i = 0; i < n; i++) if (v1[i] > v2[i]) c++;
    cout << c << endl;
    return 0;
}
