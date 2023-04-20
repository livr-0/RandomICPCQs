#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef pair<int, int> coord;

int getDirection(coord node, coord parent) {
    if (parent.first + 1 == node.first) return 1; // n
    if (parent.first - 1 == node.first) return 2; // s
    if (parent.second + 1 == node.second) return 3; // e
    if (parent.second - 1 == node.second) return 4; // w
    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<vector<bool>> grid(n, vector<bool>(n, 1));
    set<pair<int, pair<coord, coord>>> frontier;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++)
            if (row[j] == '#')
                grid[i][j] = 0;
    }
    coord target = { n - 1, n - 1 };
    int w = -1;
    frontier.insert({ 0, { { 0, 0 }, { 0, 0 } } });
    while (1) {
        int weight = (*frontier.begin()).first;
        if (w != -1 && weight >= w) break;
        coord node = (*frontier.begin()).second.first;
        coord parent = (*frontier.begin()).second.second;
        int direction = getDirection(node, parent);
        if (node == target && (w == -1 || weight < w)) w = weight;
        frontier.erase(frontier.begin());
        if (node.first > 0) {
            coord child = node; child.first--;
            if (grid[child.first][child.second]) {
                if (getDirection(child, node) == direction) frontier.insert({ weight, { child, node } });
                else frontier.insert({ weight + 1, { child, node } });
            }
        }
        if (node.first < n - 1) {
            coord child = node; child.first++;
            if (grid[child.first][child.second]) {
                if (getDirection(child, node) == direction) frontier.insert({ weight, { child, node } });
                else frontier.insert({ weight + 1, { child, node } });
            }
        }
        if (node.second > 0) {
            coord child = node; child.second--;
            if (grid[child.first][child.second]) {
                if (getDirection(child, node) == direction) frontier.insert({ weight, { child, node } });
                else frontier.insert({ weight + 1, { child, node } });
            }
        }
        if (node.second < n - 1) {
            coord child = node; child.second++;
            if (grid[child.first][child.second]) {
                if (getDirection(child, node) == direction) frontier.insert({ weight, { child, node } });
                else frontier.insert({ weight + 1, { child, node } });
            }
        }
    }
    cout << w << endl;
    return 0;
}
