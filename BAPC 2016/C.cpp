#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

struct Country {
    unordered_set<size_t> partners;
    size_t original;
};

int main() {
    int c, p, x, l;
    cin >> c >> p >> x >> l;
    x--; l--;

    if (x == l) {
        cout << "leave\n";
        return 0;
    }

    vector<Country> graph(c);

    while (p--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].partners.insert(b);
        graph[b].partners.insert(a);
    }

    for (auto &country : graph) {
        country.original = country.partners.size();
    }

    unordered_set<size_t> to_process;

    for (size_t partner : graph[l].partners) {
        graph[partner].partners.erase(l);
        to_process.insert(partner);
    }

    while (!to_process.empty()) {
        auto i = to_process.begin();
        size_t next = *i;
        to_process.erase(i);

        Country &country = graph[next];
        if (country.partners.size() <= country.original / 2) {
            if (next == x) {
                cout << "leave\n";
                return 0;
            }
            for (size_t partner : country.partners) {
                graph[partner].partners.erase(next);
                to_process.insert(partner);
            }
        }
    }

    cout << "stay\n";
}
