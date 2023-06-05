#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

size_t n, m;
set<size_t> unvisited;
vector<vector<size_t>> graph;
vector<size_t> visitedByRoad, visitedBySnow;

void initialise() {
    cin >> n >> m;
    for (size_t i = 1; i < n; i++) unvisited.insert(i);
    graph = vector<vector<size_t>>(n);
    while (m--) {
        size_t u, v;
        cin >> u >> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    for (auto& nodes : graph) sort(nodes.begin(), nodes.end());
    if (graph[0].size() > 0) {
        visitedByRoad.push_back(graph[0][0]);
        unvisited.erase(graph[0][0]);
    }
    else {
        // if 0th node is a sad lonely little node, start at 1.
        // obviously, to reach 1, we need to go by snow as there is no route.
        visitedBySnow.push_back(1);
        unvisited.erase(1);
    }
}

void searchpath() {
    while (!unvisited.empty()) {
        while (!visitedByRoad.empty()) {
            size_t initial = visitedByRoad.back();
            for (const auto& node : graph[initial])
                if (unvisited.find(node) != unvisited.end()) {
                    visitedByRoad.push_back(node);
                    unvisited.erase(node);
                    break;
                }
            if (initial == visitedByRoad.back()) break;
        }
        if (unvisited.empty()) break;
        if (visitedBySnow.empty()) {
            size_t node = *unvisited.begin();
            unvisited.erase(node);
            visitedBySnow.push_back(node);
        }
        while (!visitedBySnow.empty()) {
            size_t initial = visitedBySnow.back();
            for (const auto& node : unvisited) {
                auto i = lower_bound(graph[initial].begin(), graph[initial].end(), node);
                if (i == graph[initial].end() || node != *i) {
                    visitedBySnow.push_back(node);
                    unvisited.erase(node);
                    break;
                }
            }
            if (initial == visitedBySnow.back()) break;
        }
        if (unvisited.empty()) break;
        if (visitedByRoad.empty()) {
            size_t node = *unvisited.begin();
            unvisited.erase(node);
            visitedByRoad.push_back(node);
        }
        size_t lastVisitedByRoad = visitedByRoad.back(), lastVisitedBySnow = visitedBySnow.back();
        auto i = lower_bound(graph[lastVisitedByRoad].begin(), graph[lastVisitedByRoad].end(), lastVisitedBySnow);
        if (i != graph[lastVisitedByRoad].end() && *i == lastVisitedBySnow) {
            visitedByRoad.push_back(visitedBySnow.back());
            visitedBySnow.pop_back();
        }
        else {
            visitedBySnow.push_back(visitedByRoad.back());
            visitedByRoad.pop_back();
        }
    }
}

void showResult() {
    cout << "1 ";
    if (visitedByRoad.empty())
        for (const auto& node : visitedBySnow)
            cout << node + 1 << " ";
    else {
        auto i = lower_bound(graph[0].begin(), graph[0].end(), visitedByRoad[0]);
        if (i != graph[0].end() && *i == visitedByRoad[0]) {
            for (const auto& node : visitedByRoad) cout << node + 1 << " ";
            for (const auto& node : visitedBySnow) cout << node + 1 << " ";
        }
        else {
            for (const auto& node : visitedBySnow) cout << node + 1 << " ";
            for (const auto& node : visitedByRoad) cout << node + 1 << " ";
        }
    }
    cout << endl;
}

int main() {
    initialise();
    searchpath();
    showResult();
    return 0;
}
