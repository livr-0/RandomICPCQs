#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

size_t n, a, b;
vector<set<size_t>> adjacencyList;

void initialise() {
    cin >> n;
    a = 0;
    b = 0;
    adjacencyList = vector<set<size_t>>(n + 1);
    for (size_t i = 0; i < n - 1; i++) {
        size_t u, v;
        cin >> u >> v;
        adjacencyList[u].insert(v);
        adjacencyList[v].insert(u);
    }
}

void pairpicker() {
    for (size_t i = 1; i <= n; i++)
        if (adjacencyList[i].size() >= 2)
            for (const auto& node: adjacencyList[i])
                if (adjacencyList[node].size() >= 2) {
                    a = i;
                    b = node;
                    break;
                }
}

void pathfinder() {
    if (!a) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    set<size_t> visited;
    queue<size_t> frontier;
    frontier.push(a);
    adjacencyList[a].erase(b);
    while (!frontier.empty()) {
        size_t node = frontier.front();
        frontier.pop();
        if (visited.count(node)) continue;
        visited.insert(node);
        cout << node << " ";
        for (const size_t& child : adjacencyList[node])
            if (!visited.count(child)) frontier.push(child);
        if (node == a) frontier.push(b);
    }
    cout << endl;
}

int main() {
    initialise();
    pairpicker();
    pathfinder();
    return 0;
}
