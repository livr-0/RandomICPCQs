#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const size_t costLim = 2000 + 1;

int main() {
    size_t n, e, m, c;
    cin >> n >> e;
    vector<pair<size_t, size_t>> gpus;
    while (n--) {
        cin >> m >> c;
        gpus.emplace_back(c, m);
    }

    vector<vector<size_t>> memo(gpus.size() + 1, vector<size_t>(e + 1, 0));
    for (size_t i = 1; i <= gpus.size(); i++) {
        for (size_t j = 1; j <= e; j++) {
            if (gpus[i - 1].first > j) memo[i][j] = memo[i - 1][j];
            else {
                memo[i][j] = max(memo[i - 1][j], 
                memo[i - 1][j - gpus[i - 1].first] + 
                (gpus[i - 1].first * costLim - gpus[i - 1].second)
                );
            }
        }
    }

    size_t cost = 0;
    for (size_t i = gpus.size(), w = e; i > 0; i--) {
        if (memo[i][w] != memo[i - 1][w]) {
            cost += gpus[i - 1].second;
            w -= gpus[i - 1].first;
        }
    }

    cout << cost << endl;
    return 0;
}
