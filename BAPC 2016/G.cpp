#include <cmath>
#include <iostream>
#include <queue>
#include <tuple>
#include <set>

using namespace std;

int main() {
    size_t num_beacons;
    cin >> num_beacons;
    
    priority_queue<tuple<int, int, int>> queue;
    set<pair<int, int>> candidates;

    while (num_beacons--) {
        int x, y, d;
        cin >> x >> y >> d;
        queue.push({-d, x, y});
    }

    auto [dist, x, y] = queue.top();
    queue.pop();
    dist *= -1;
    for (int i = 0; i < dist; i++) {
        candidates.insert({x + i, y + dist - i});
        candidates.insert({x + dist - i, y - i});
        candidates.insert({x - i, y - dist + i});
        candidates.insert({x - dist + i, y + i});
    }

    while (!queue.empty()) {
        auto [dist, x, y] = queue.top();
        queue.pop();
        
        set<pair<int, int>> to_erase;
        for (const auto cand : candidates) {
            auto [cx, cy] = cand;
            int cdist = abs(cx - x) + abs(cy - y);
            if (-dist != cdist) {
                to_erase.insert(cand);
            }
        }
        for (const auto cand : to_erase) {
            candidates.erase(cand);
        }
    }

    if (candidates.size() == 0) {
        cout << "impossible\n";
    } else if (candidates.size() > 1) {
        cout << "uncertain\n";
    } else {
        auto [x, y] = *candidates.begin();
        cout << x << ' ' << y << endl;
    }
}
