#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    size_t n, m;
    cin >> n >> m;
    unordered_map<int, int> um;
    int x;

    for (size_t i = 1; i <= n; i++) {
        cin >> x;
        um[i] = x;
    }

    int a = um[m];

    size_t count = 0;

    if (a != m) {
        count++;
    }

    while (a != m) {
        a = um[a];
        count++;
    }

    cout << count;

    return 0;
}
