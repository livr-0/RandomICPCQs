#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

struct Node {
    char first, last;
    string prefix;
    string suffix;
    Node(string s) {
        first = s[0];
        last = s[s.size() - 1];
        prefix = s.substr(0, s.size() - 1);
        suffix = s.substr(1, s.size());
    }
};

vector<Node> nodes;
multiset<string> stringsCounter;
unordered_map<Node*, unordered_set<Node*>> graph;

void dfs(vector<Node*>& path, unordered_set<Node*>& visited) {
    Node* current = path[path.size() - 1];
    visited.insert(current);
    if (path.size() == nodes.size()) return;
    for (const auto& child : graph[current]) {
        if (!visited.count(child)) {
            path.push_back(child);
            dfs(path, visited);
            if (path.size() == nodes.size()) return;
            path.pop_back();
        }
    }
    visited.erase(current);
}

void showResult(vector<Node*>& path) {
    for (const auto& node : path) cout << node->first;
    cout << path[path.size() - 1]->suffix << endl;
}

int main() {
    size_t n, k;
    cin >> n >> k;
    for (size_t i = 0; i < n - k; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        s1 += s2[s2.size() - 1];
        Node n(s1);
        stringsCounter.insert(s1);
        nodes.push_back(n);
    }
    size_t edge = 0;
    for (size_t i = 0; i < nodes.size(); i++) {
        for (size_t j = 0; j < nodes.size(); j++) {
            if (i != j && nodes[i].suffix == nodes[j].prefix) {
                graph[&nodes[i]].insert(&nodes[j]);
            }
        }
    }
    for (size_t i = 0; i < nodes.size(); i++) {
        vector<Node*> path = { &nodes[i] };
        unordered_set<Node*> visited;
        dfs(path, visited);
        if (path.size() == nodes.size()) {
            showResult(path);
            return 0;
        }
    }
    return 0;
}
