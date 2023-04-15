#include <iostream>
#include <map>
#include <set>

using namespace std;

set<int> c;
map<int, set<int>> t;

int bfs(int target, set<int> visited = {}) {
    if (target > c.size()) return 0;
    for (const int& node : visited)
        if (t[node].count(target))
            return bfs(target + 1, visited);
    int min = 1e8;
    for (const pair<int, set<int>>& v : t)
        if (visited.count(v.first) == 0 && v.second.count(target)) {
            set<int> tV(visited);
            tV.insert(v.first);
            int res = 1 + bfs(target + 1, tV);
            if (res < min) min = res;
        }
    return min;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int q;
        cin >> q;
        while (q--) {
            int p;
            cin >> p;
            t[i].insert(p);
            c.insert(p);
        }
    }
    if (c.size() != m) cout << -1 << endl;
    else cout << bfs(1) << endl;
    return 0;
}
