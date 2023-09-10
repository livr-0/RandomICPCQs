#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>

using namespace std;

int main() {
    long maxDeliciousness = 0;
    int n;
    cin >> n;
    vector<tuple<long, long, long>> layers(n);
    for (int i = 0; i < n; i++) cin >> get<0>(layers[i]) >> get<1>(layers[i]) >> get<2>(layers[i]);
    sort(layers.begin(), layers.end());
    do {
        long weight = 0, deliciousness = 0;
        for (int i = layers.size() - 1; i >= 0; i--) {
            weight += get<0>(layers[i]);
            if (get<1>(layers[i]) < weight) {
                break;
            }
            deliciousness += get<2>(layers[i]);
        }
        maxDeliciousness = max(maxDeliciousness, deliciousness);
    } while (next_permutation(layers.begin(), layers.end()));
    cout << maxDeliciousness << endl;
    return 0;
}
