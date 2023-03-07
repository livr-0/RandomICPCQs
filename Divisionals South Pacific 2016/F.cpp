#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef pair<size_t, size_t> coord;
typedef pair<size_t, coord> weightedCoord;
typedef pair<weightedCoord, coord> coordInPath; // { {child, weight}, parent }

size_t rowCount, colCount;
coord startPos, endPos;
vector<vector<char>> grid;
map<coord, weightedCoord> foundBy; // child: { weight, parent }
set<coordInPath> frontier;

const size_t INF = 1e8;
const weightedCoord UNKNOWN = { INF, { INF, INF } };

void getGrid() {
    cin >> rowCount >> colCount;
    bool foundStartPos = false;
    for (size_t i = 0; i < rowCount; i++) {
        vector<char> row;
        string s;
        cin >> s;
        for (size_t j = 0; j < colCount; j++) {
            if (s[j] == 'A') {
                if (!foundStartPos) {
                    startPos = { i, j };
                    foundStartPos = true;
                }
                else endPos = { i, j };
            }
            row.push_back(s[j]);
        }
        grid.push_back(row);
    }
}

void initialiseSearchVariables() {
    frontier.clear();
    foundBy.clear();

    for (size_t i = 0; i < rowCount; i++) {
        for (size_t j = 0; j < colCount; j++) {
            foundBy[{ i, j }] = UNKNOWN;
        }
    }

    frontier.insert({{ 0, startPos }, startPos});
}

void insertToFrontier(coord newNode, size_t weight, coord newParent) {
    weightedCoord oldParent = foundBy[newNode];
    size_t newWeight = ((grid[newNode.first][newNode.second] == 'O') ? ( weight + 1 ) : (weight));
    if (oldParent == UNKNOWN || oldParent.first > newWeight) frontier.insert({ { newWeight, newNode }, newParent });
}

void dijkstra() {
    if (frontier.empty()) return;

    coordInPath w = *frontier.begin();
    size_t weight = w.first.first;
    coord node = w.first.second, parent = w.second;
    size_t r = node.first, c = node.second;

    frontier.erase(w);
    if (foundBy[node] != UNKNOWN) return;
    foundBy[node] = { weight, parent };

    if (node == endPos) {
        frontier.clear();
        return;
    }

    if (r != 0 && grid[r-1][c] != '#') insertToFrontier({ r-1, c }, weight, node);
    if (r != rowCount - 1 && grid[r+1][c] != '#') insertToFrontier({ r+1, c }, weight, node);
    if (c != 0 && grid[r][c-1] != '#') insertToFrontier({ r, c-1 }, weight, node);
    if (c != colCount - 1 && grid[r][c+1] != '#') insertToFrontier({ r, c+1 }, weight, node);

    while(!frontier.empty()) dijkstra();
}

void discoverDeuteriumOnPath(set<coord>& discovered, coord pos) {
    if (pos == startPos || foundBy[pos] == UNKNOWN) return;
    if (grid[pos.first][pos.second] == 'O') discovered.insert(pos);
    discoverDeuteriumOnPath(discovered, foundBy[pos].second);
}

bool findDeuteriumMate(set<coord>& visited, set<coord>& ignorables, coord pos) {
    visited.insert(pos);

    size_t r = pos.first, c = pos.second;

    if (grid[r][c] == 'O' && ignorables.find(pos) == ignorables.end()) return true;

    if (r != 0 && grid[r-1][c] != 'A' && grid[r-1][c] != '#' && visited.find({ r-1, c }) == visited.end()) {
        if (findDeuteriumMate(visited, ignorables, { r-1, c })) return true;
    }
    if (r != rowCount - 1 && grid[r+1][c] != 'A' && grid[r+1][c] != '#' && visited.find({ r+1, c }) == visited.end()) {
        if (findDeuteriumMate(visited, ignorables, { r+1, c })) return true;
    }
    if (c != 0 && grid[r][c-1] != 'A' && grid[r][c-1] != '#' && visited.find({ r, c-1 }) == visited.end()) {
        if (findDeuteriumMate(visited, ignorables, { r, c-1 })) return true;
    }
    if (c != colCount - 1 && grid[r][c+1] != 'A' && grid[r][c+1] != '#' && visited.find({ r, c+1 }) == visited.end()) {
        if (findDeuteriumMate(visited, ignorables, { r, c+1 })) return true;
    }

    return false;
}

bool checkSearchResult() {
    if (foundBy[endPos] == UNKNOWN) {
        cout << "-1" << endl;
        return true;
    }

    set<coord> deuteriumAtomsOnPath, visited;
    discoverDeuteriumOnPath(deuteriumAtomsOnPath, endPos);

    if (deuteriumAtomsOnPath.size() % 2 == 0) {
        cout << (deuteriumAtomsOnPath.size() / 2) + 1 << endl;
        return true;
    }

    if (findDeuteriumMate(visited, deuteriumAtomsOnPath, *deuteriumAtomsOnPath.begin())) {
        cout << ((deuteriumAtomsOnPath.size() + 1) / 2) + 1 << endl;
        return true;
    }

    for (const coord& newWall : deuteriumAtomsOnPath) grid[newWall.first][newWall.second] = '#';
    return false;
}

int main() {
    getGrid();
    while (1) {
        initialiseSearchVariables();
        dijkstra();
        if (checkSearchResult()) break;
    }
    return 0;
}
