#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    map<size_t, size_t> res;
    map<size_t, size_t> cards;
    size_t n, p, c, m = 1e8;
    cin >> n >> p >> c;
    for (size_t i = 1; i <= n; i++) {
        size_t x;
        cin >> x;
        cards[x] = i;
    }
    for (size_t i = 0; i < p; i++) {
        size_t lm = 1;
        for (size_t j = 0; j < c; j++) {
            size_t x;
            cin >> x;
            if (lm) {
                if (!cards.count(x)) lm = 0;
                else if (cards[x] > lm) lm = cards[x];
            }
        }
        res[i] = lm;
        if (lm && lm < m) m = lm;
    }
    for (const auto& r : res) {
        if (r.second == 0) cout << "hopeless" << endl;
        else if (r.second == m) cout << "winning" << endl;
        else cout << "losing" << endl;
    }
    return 0;
}
