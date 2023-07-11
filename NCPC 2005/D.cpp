#include <iostream>
#include <vector>

using namespace std;

int main() {
    size_t n, k, m = 0;
    cin >> n >> k;
    vector<size_t> req_arrivals(n);
    for (size_t i = 0; i < n; i++) cin >> req_arrivals[i];
    size_t j = 0;
    for (size_t i = 0; i < n; i++) {
        size_t c = j - i;
        for (; j < n; j++) {
            if (req_arrivals[j] - req_arrivals[i] < 1000) {
                c++;
            } else break;
        }
        if (c > m) m = c;
        if (j == n - 1) break;
    }
    cout << (m + (k - 1)) / k << endl;
    return 0;
}
