#include <bits/stdc++.h>

using namespace std;

const size_t inf = 1e8;
typedef pair<size_t, pair<size_t, size_t>> weight;
weight infw = { inf, { inf, inf } }; // { titan, { shaman, dist } }

struct Node {
    bool explored;
    size_t id;
    weight shortest;
    unordered_map<size_t, weight> paths;
    Node(size_t aId) {
        id = aId;
        shortest = infw;
        paths = {};
        explored = 0;
    }
};

size_t pickCurrent(const vector<Node>& nodes) {
    size_t id = 0;
    weight wt = infw;
    for (size_t i = 0; i < nodes.size(); i++) {
        if (!nodes[i].explored && nodes[i].shortest < wt) {
            wt = nodes[i].shortest;
            id = i;
        }
    }
    return id;
}

int main() {
    size_t n, w, x, y;
    cin >> n >> w >> x >> y;
    x--; y--;

    vector<Node> nodes;
    for (size_t i = 0; i < n; i++) {
        Node nd(i);
        nodes.push_back(nd);
    }
    nodes[x].shortest = { 0, { 0, 0 } };

    for (size_t i = 0; i < w; i++) {
        size_t a, b, w, c;
        cin >> a >> b >> w >> c;
        a--; b--;

        weight wt = { 0, { 0, w } };
        if (c == 2) wt.first = 1;
        else if (c == 1) wt.second.first = 1;

        nodes[a].paths[b] = wt;
        nodes[b].paths[a] = wt;
    }

    size_t currentID = pickCurrent(nodes);

    while (true) {
        Node current = nodes[currentID];

        if (current.id == y) break;

        for (const auto& path : current.paths) {
            size_t dest = path.first;
            weight newWeight = path.second;
            newWeight.first += current.shortest.first;
            newWeight.second.first += current.shortest.second.first;
            newWeight.second.second += current.shortest.second.second;
            if (nodes[dest].shortest > newWeight) {
                nodes[dest].shortest = newWeight;
            }
        }

        nodes[currentID].explored = 1;

        size_t newID = pickCurrent(nodes);
        if (newID == currentID) break;
        currentID = newID;
    }

    if (nodes[y].shortest == infw) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << nodes[y].shortest.second.second << " " << nodes[y].shortest.second.first << " " << nodes[y].shortest.first << endl;
    }

    return 0;
}
