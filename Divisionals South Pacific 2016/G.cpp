#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<size_t>> g(10, vector<size_t>(10, 1));
    size_t n;
    cin >> n;
    while (n-- > 0) {
        size_t a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        a--; b--; c--; d--; e--; f--;
        for (size_t i = 0; i < 10; i++) {
            if (i == a || i == b || i == c) g[i] = vector<size_t>(10, 1);
            else {
                for (size_t j = 0; j < 10; j++) {
                    if (j == d || j == e || j == f) g[i][j] = 1;
                    else g[i][j]++;
                }
            }
        }
    }
    for (const auto& a : g) {
        for (const auto& b : a) cout << b << " ";
        cout << endl;
    }
    return 0;
}
