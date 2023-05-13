#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

size_t n, m;
vector<unordered_set<size_t>> lists = {};
unordered_map<size_t, unordered_set<size_t>> routes = {};
queue<size_t> frontier = {};
unordered_map<size_t, size_t> parent = {};

size_t traverseBack() {
    size_t current = n, c = 0;
    while (current != 1) {
        current = parent[current];
        c++;
    }
    return c;
}

long long bfs() {
    frontier.push(1);
    parent[1] = 1;
    while (!frontier.empty()) {
        size_t current = frontier.front();
        frontier.pop();
        if (current == n) return traverseBack();
        for (const auto& child : routes[current])
            if (!parent.count(child)) {
                frontier.push(child);
                parent[child] = current;
            }
    }
    return -1;
}

int main() {
    cin >> n >> m;
    for (size_t i = 1; i <= n; i++) routes[i] = {};
    while (m--) {
        unordered_set<size_t> list = {};
        size_t c;
        cin >> c;
        while (c--) {
            size_t x;
            cin >> x;
            list.insert(x);
        }
        lists.push_back(list);
    }
    for (size_t i = 1; i <= n; i++) {
        size_t x;
        cin >> x;
        routes[i] = lists[x - 1];
    }
    cout << bfs() << endl;
    return 0;
}
