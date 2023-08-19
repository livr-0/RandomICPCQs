#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> coord;

map<coord, set<coord>> graph;
map<coord, bool> used;

double walker = 10.0 * 100 / 6.0, subway = 40.0 * 100 / 6.0;

double distance(coord x, coord y) {
    return sqrt(pow(x.first - y.first, 2) + pow(x.second - y.second, 2));
}

double distanceToTime(double distance, double speed) {
    return distance / speed;
}

void fillRoutes(vector<coord>& routes) {
    for (int i = 0; i < routes.size() - 1; i++) {
        for (int j = i + 1; j < routes.size(); j++) {
            graph[routes[i]].insert(routes[j]);
            graph[routes[j]].insert(routes[i]);
        }
    }
}

double dijkstra(coord home, coord uni) {
    set<coord> visited;
    priority_queue<pair<double, coord>> frontier;
    frontier.push({ 0, home });
    while (frontier.size()) {
        double time = -frontier.top().first;
        coord pos = frontier.top().second;
        visited.insert(pos);
        frontier.pop();
        if (pos == uni) return time;
        used[pos] = 1;
        for (const coord& child : graph[pos]) {
            if (!visited.count(child)) {
                frontier.push({ -(time + distanceToTime(distance(pos, child), subway)), child });
                used[child] = 1;
            }
        }
        for (auto& nodes : used) {
            if (!visited.count(nodes.first)) {
                if (nodes.second) used[nodes.first] = 0;
                else frontier.push({ -(time + distanceToTime(distance(pos, nodes.first), walker)), nodes.first });
            }
        }
    }
    return -1;
}

int main() {
    coord home, uni;
    size_t n;
    cin >> home.first >> home.second >> uni.first >> uni.second >> n;
    used[home] = 0;
    used[uni] = 0;
    vector<coord> routes;
    while (n--) {
        routes.clear();
        coord x;
        cin >> x.first >> x.second;
        while (x.first >= 0) {
            routes.push_back(x);
            used[x] = 0;
            cin >> x.first >> x.second;
        }
        fillRoutes(routes);
    }
    cout << int(round(dijkstra(home, uni))) << endl;
    return 0;
}
