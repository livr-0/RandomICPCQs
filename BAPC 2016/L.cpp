#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    size_t n;
    cin >> n;
    vector<size_t> s(n);
    for (size_t i = 0; i < n; i++)
        cin >> s[i];
    sort(s.begin(), s.end());
    for (size_t i = 0; i < n - 2; i++)
        if (s[i] + s[i + 1] > s[i + 2]) {
            cout << "possible" << endl;
            return 0;
        }
    cout << "impossible" << endl;
    return 0;
}
