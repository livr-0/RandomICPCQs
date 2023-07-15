#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

size_t c;
unordered_set<size_t> explored;
unordered_map<size_t, unordered_set<size_t>> graph;
vector<size_t> diameters;

void makeMap() {
    size_t t;
    cin >> c >> t;
    while (t--) {
        size_t u, v;
        cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }
}

void findDiameter(size_t i) {
    queue<size_t> frontier;
    frontier.push(i);
    size_t lastPopped = i;
    while (!frontier.empty()) {
        size_t node = frontier.front();
        frontier.pop();
        explored.insert(node);
        lastPopped = node;
        for (const size_t& child : graph[node])
            if (!explored.count(child))
                frontier.push(child);
    }
    unordered_set<size_t> visited;
    queue<pair<size_t, size_t>> frontier2;
    frontier2.push({ lastPopped, 0 });
    lastPopped = 0;
    while (!frontier2.empty()) {
        size_t node = frontier2.front().first;
        size_t distance = frontier2.front().second;
        frontier2.pop();
        visited.insert(node);
        if (lastPopped < distance)
            lastPopped = distance;
        for (const size_t& child : graph[node])
            if (!visited.count(child))
                frontier2.push({ child, distance + 1 });
    }
    diameters.push_back(lastPopped);
}

void findDiameters() {
    for (size_t i = 0; i < c; i++)
        if (!explored.count(i))
            findDiameter(i);
    sort(diameters.rbegin(), diameters.rend());
}

void findResult() {
    size_t result = max((double)diameters[0], max(
        ceil((double)diameters[0]/2) + ceil((double)diameters[1]/2) + 1,
        ceil((double)diameters[1]/2) + ceil((double)diameters[2]/2) + 2
    ));
    cout << result << endl;
}

int main() {
    makeMap();
    findDiameters();
    findResult();
    return 0;
}
