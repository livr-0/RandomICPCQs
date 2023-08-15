#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>

using namespace std;

typedef pair<int, int> coord;

map<coord, map<char, set<char>>> graph;

char getNewDir(char currentDir, char bearing) {
    if (bearing == 'F') return currentDir;
    if (bearing == 'R') {
        if (currentDir == 'N') return 'E';
        if (currentDir == 'S') return 'W';
        if (currentDir == 'E') return 'S';
        return 'N';
    }
    if (currentDir == 'N') return 'W';
    if (currentDir == 'S') return 'E';
    if (currentDir == 'E') return 'N';
    return 'S';
}

coord getPosFromDir(coord currentPos, char dir) {
    coord res = currentPos;
    if (dir == 'N') res.first--;
    if (dir == 'S') res.first++;
    if (dir == 'W') res.second--;
    if (dir == 'E') res.second++;
    return res;
}

int bfs(coord start, coord goal, char dir) {
    unordered_set<string> visited;
    if (start == goal) return 0;
    start = getPosFromDir(start, dir);
    queue<pair<coord, pair<char, int>>> frontier; // { position, { incoming direction, depth } }
    frontier.push({ start, { dir, 1 } });
    while (frontier.size()) {
        coord position = frontier.front().first;
        char direction = frontier.front().second.first;
        int depth = frontier.front().second.second;
        frontier.pop();
        string s = to_string(position.first) + "," + to_string(position.second) + direction;
        if (visited.count(s)) continue;
        visited.insert(s);
        if (position == goal) return depth;
        if (depth > 82) return -1;
        for (const char& bearing : graph[position][direction]) {
            char newDirection = getNewDir(direction, bearing);
            coord newPosition = getPosFromDir(position, newDirection);
            frontier.push({ newPosition, { newDirection, depth + 1 } });
        }
    }
    return -1;
}

int main() {
    while (1) {
        graph.clear();
        string s;
        cin >> s;
        if (s == "END") break;
        cout << s << endl;
        coord start, goal, point;
        char startDir;
        cin >> start.first >> start.second >> startDir >> goal.first >> goal.second;
        cin >> point.first;
        while (point.first) {
            cin >> point.second;
            string q;
            cin >> q;
            while (q != "*") {
                for (int i = 1; i < q.size(); i++) graph[point][q[0]].insert(q[i]);
                cin >> q;
            }
            cin >> point.first;
        }
        int res = bfs(start, goal, startDir);
        if (res < 0) cout << "No Solution Possible" << endl;
        else cout << "Solved in " << res << " steps" << endl;
    }
    return 0;
}
