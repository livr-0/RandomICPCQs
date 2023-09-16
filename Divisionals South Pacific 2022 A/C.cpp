#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<unordered_set<int>> lists(m + 1);
    vector<int> edgesListIndex(n + 1);

    for (int i = 1; i <= m; i++) {
        int c;
        cin >> c;
        while (c--) {
            int v;
            cin >> v;
            lists[i].insert(v);
        }
    }

    for (int i = 1; i <= n; i++) {
        cin >> edgesListIndex[i];
    }

    unordered_set<int> seen = { 1 };
    queue<pair<int, int>> frontier;
    frontier.push({ 1, 0 });
    while (frontier.size()) {
        int node = frontier.front().first;
        int depth = frontier.front().second;
        frontier.pop();
        if (node == n) {
            cout << depth << endl;
            return 0;
        }
        vector<int> edgesToRemove;
        for (int child : lists[edgesListIndex[node]]) {
            if (!seen.count(child)) {
                seen.insert(child);
                frontier.push({ child, depth + 1 });
            } else {
                edgesToRemove.push_back(child);
            }
        }
        for (int edge : edgesToRemove) {
            lists[edgesListIndex[node]].erase(edge);
        }
    }
    cout << -1 << endl;

    return 0;
}
