#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;

int main() {
    unordered_set<size_t> squares, cubes;
    size_t l, r, squbes = 0;
    cin >> l >> r;
    size_t i = sqrt((double)(l));
    while (1) {
        size_t sq = i * i;
        if (sq >= l && sq <= r) squares.insert(sq);
        else if (sq > r) break;
        i++;
    }
    i = cbrt((double)(l));
    while (1) {
        size_t cb = i * i * i;
        if (cb >= l && cb <= r) {
            cubes.insert(cb);
            if (squares.find(cb) != squares.end()) squbes++;
        }
        else if (cb > r) break;
        i++;
    }
    cout << squares.size() << " " << cubes.size() << " " << squbes << endl;
    return 0;
}
