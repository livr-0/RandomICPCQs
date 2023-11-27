#include <bits/stdc++.h>

using namespace std;

struct Node {
    int parentId;
    set<int> children, weaks;
    Node() { parentId = -1; }
};

void clearWeaks(int id, vector<Node>& nodes) {
    Node& node = nodes[id];
    for (int weak : node.weaks) {
        Node& weakNode = nodes[weak];
        weakNode.parentId = id;
        weakNode.weaks.erase(id);
        clearWeaks(weak, nodes);
    }
    node.weaks.clear();
}

int main () {
    int n;
    cin >> n;

    vector<Node> nodes(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        char c;
        cin >> u >> c >> v;

        if (c == '>') {
            nodes[v].parentId = u;
            nodes[u].children.insert(v);
        } else {
            nodes[v].weaks.insert(u);
            nodes[u].weaks.insert(v);
        }
    }

    for (int i = 0; i < n; i++)
        if (nodes[i].weaks.size() && nodes[i].parentId != -1)
            clearWeaks(i, nodes);

    for (int i = 0; i < n; i++)
        if (nodes[i].parentId == -1)
            cout << i << " ";
    cout << endl;
    return 0;
}
