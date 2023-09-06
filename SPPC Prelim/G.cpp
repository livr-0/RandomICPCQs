#include <bits/stdc++.h>

using namespace std;

enum NodeType { START, END, RED, BLUE };

struct Node {
    NodeType type;
    string value;
    Node(NodeType t, string s = "") { type = t; value = s; }
};

size_t n, k;
vector<Node> nodes;
unordered_map<Node*, unordered_set<Node*>> edges;
unordered_map<string, pair<size_t, size_t>> counts;

void createNodes() {
    nodes.reserve(n * 2 + 1);
    nodes.push_back(Node(START));
    for (size_t i = 0; i < (n - k); i++) {
        string s1, s2;
        cin >> s1 >> s2;
        nodes.push_back(Node(RED, s1));
        nodes.push_back(Node(BLUE, s2));
        edges[&nodes[nodes.size() - 2]].insert(&nodes[nodes.size() - 1]);
        counts[s1].first++;
        counts[s2].second++;
    }
    nodes.push_back(Node(END));
}

void createEdges() {
    bool startSet = false, endSet = false;

    for (auto& c : counts) {
        if (c.second.first > c.second.second) {
            startSet = true;
            for (auto& node : nodes)
                if (node.type == RED && node.value == c.first)
                    edges[&nodes[0]].insert(&node);
        } else if (c.second.first < c.second.second) {
            endSet = true;
            for (auto& node : nodes)
                if (node.type == BLUE && node.value == c.first)
                    edges[&node].insert(&nodes[nodes.size() - 1]);
        }
    }

    if (!startSet) {
        for (auto& node : nodes)
            if (node.type == RED)
                edges[&nodes[0]].insert(&node);
    }

    if (!endSet) {
        for (auto& node : nodes)
            if (node.type == BLUE)
                edges[&node].insert(&nodes[nodes.size() - 1]);
    }

    for (size_t i = 1; i < nodes.size() - 1; i++)
        if (nodes[i].type == BLUE)
            for (size_t j = 1; j < nodes.size() - 1; j++)
                if (nodes[j].type == RED && nodes[j].value == nodes[i].value)
                    edges[&nodes[i]].insert(&nodes[j]);
}

void dfs(vector<Node*>& path, unordered_set<Node*>& visited) {
    Node* current = path[path.size() - 1];
    visited.insert(current);
    if (path.size() == nodes.size()) return;
    for (auto& child : edges[current]) {
        if (!visited.count(child)) {
            path.push_back(child);
            dfs(path, visited);
            if (path.size() == nodes.size()) return;
            path.pop_back();
        }
    }
    visited.erase(current);
}

void doMatching() {
    vector<Node*> path = { &nodes[0] };
    unordered_set<Node*> visited;
    dfs(path, visited);
    for (size_t i = 1; i < nodes.size() - 1; i += 2)
        cout << path[i]->value[0];
    cout << path[path.size() - 2]->value << endl;
}

int main() {
    cin >> n >> k;
    createNodes();
    createEdges();
    doMatching();
    return 0;
}
