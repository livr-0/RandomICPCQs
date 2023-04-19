#include <iostream>
#include <vector>
#include <set>

using namespace std;

size_t maxSeen;

void traverse(size_t i, size_t n, multiset<set<size_t>> keys = {}) {
    size_t x;
    cin >> x;
    if (!x) {
        multiset<set<size_t>> dKeys(keys);
        for (const set<size_t>& key : keys) {
            if (key.count(i)) {
                if (maxSeen < i) maxSeen = i;
                if (maxSeen == n) return;
                int c = keys.count(key);
                c--;
                dKeys.erase(key);
                for (size_t i = 0; i < c; i++) dKeys.insert(key);
                traverse(i+1, n, dKeys);
                dKeys = keys;
            }
        }
    } else {
        if (maxSeen < i) maxSeen = i;
        if (maxSeen == n) return;
        set<size_t> key;
        while (x--) {
            size_t r;
            cin >> r;
            key.insert(r);
        }
        keys.insert(key);
        traverse(i+1, n, keys);
    }
}

int main() {
    size_t n;
    cin >> n;
    maxSeen = 1;
    traverse(1, n);
    cout << maxSeen << endl;
    return 0;
}
