#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

unordered_map<int, unordered_set<int>> graph;

unordered_set<int> getSingles() {
    unordered_set<int> result;
    for (const auto& match : graph)
        if (match.second.size() == 1)
            result.insert(match.first);
    return result;
}

bool verifyLosers(unordered_set<int>& losers) {
    for (const auto& loser : losers) {
        if (graph[loser].size() != 1) return false;
        int opponent = *graph[loser].begin();
        if (graph[opponent].size() <= 1) return false;
    }
    return true;
}

void removeLosers(unordered_set<int>& losers) {
    for (const auto& loser : losers) {
        int opponent = *graph[loser].begin();
        graph[opponent].erase(loser);
        graph.erase(loser);
    }
}

void specialCase() {
    if (graph.size() != 2) {
        cout << "MISTAKE" << endl;
        return;
    }
    for (const auto& match : graph) {
        if (match.second.size() != 1) {
            cout << "MISTAKE" << endl;
            return;
        }
        if (match.second.count(match.first)) {
            cout << "MISTAKE" << endl;
            return;
        }
        if (!graph.count(*match.second.begin())) {
            cout << "MISTAKE" << endl;
            return;
        }
    }
    cout << "OK" << endl;
}

int main() {
    int n, p = 0, m = 0;
    cin >> n;

    if (n == 1) {
        cout << "OK" << endl;
        return 0;
    }

    p = pow(2, n);

    for (int i = 0; i < pow(2, n) - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }

    while (1) {
        if (p == 2) {
            specialCase();
            break;
        }

        unordered_set<int> gs = getSingles();
        if (gs.size() != p / 2) {
            cout << "MISTAKE" << endl;
            return 0;
        }

        if (!verifyLosers(gs)) {
            cout << "MISTAKE" << endl;
            return 0;
        }

        removeLosers(gs);
        p /= 2;
    }

    return 0;
}
