// Fails with RUN-ERROR

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    size_t n, q;
    cin >> n >> q;

    vector<size_t> str(n);
    vector<unordered_set<size_t>> indices(n);
    for (size_t i = 0; i < n; i++) {
        str[i] = i;
        indices[i].insert(i);
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            size_t l, r;
            cin >> l >> r;
            l--; r--;
            for (size_t i = 0; i <= (r - l) / 2; i++) {
                const size_t& old_char = str[r - i];
                const size_t& new_char = str[l + i];
                if (old_char == new_char) continue;

                auto& old_idx = indices[old_char];
                auto& new_idx = indices[new_char];
                new_idx.insert(old_idx.begin(), old_idx.end());
                for (size_t idx : old_idx) {
                    str[idx] = new_char;
                }
            }
        } else {
            size_t a, b, x, y;
            cin >> a >> b >> x >> y;
            a--; b--; x--; y--;
            if (b - a != y - x) {
                cout << "Not equal\n";
                continue;
            }
            bool eq = true;
            for (size_t i = 0; i <= (b - a); i++) {
                if (str[a + i] != str[x + i]) {
                    eq = false;
                    break;
                }
            }
            if (eq) cout << "Equal\n";
            else cout << "Unknown\n";
        }
    }
}
