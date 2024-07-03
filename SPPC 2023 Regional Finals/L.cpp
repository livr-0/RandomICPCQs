#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;

int main() {
    uint n, f, r = 0;
    cin >> n >> f;

    vector<pair<uint, uint>> edges;
    for (int i = 0; i < f; i++) {
        uint u, v;
        cin >> u >> v;
        edges.push_back({ u - 1, v - 1 });
    }

    for (uint i = 0; i < pow(2, n); i++) {
        bitset<16> b(i);
        uint c = 0;

        for (const auto& edge : edges) {
            if (b[edge.first] != b[edge.second]) {
                c++;
            }
        }

        r = max(r, c);
    }

    cout << r << endl;
    return 0;
}
