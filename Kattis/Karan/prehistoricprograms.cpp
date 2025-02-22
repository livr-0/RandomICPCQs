#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    int net_openers = 0, net_closers = 0, net_loaded = 0;
    unordered_set<int> balanced, all_openers, all_closers;
    set<pair<pair<int, int>, int>> loaded;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int openers = 0, closers = 0;
        for (char &c : s)
            if (c == '(') openers++;
            else if (openers > 0) openers--;
            else closers++;
        if (openers == 0 && closers == 0) balanced.insert(i);
        else if (closers == 0) {
            all_openers.insert(i);
            net_openers += openers;
        } else if (openers == 0) {
            all_closers.insert(i);
            net_closers -= closers;
        } else {
            loaded.insert({ { closers, -openers }, i });
            net_loaded += openers - closers;
        }
    }

    if (net_openers + net_closers + net_loaded != 0) {
        cout << "impossible" << endl;
        return 0;
    }

    vector<int> loaded_result_builder;
    int score_right_now = net_openers;

    for (auto& [ counts, index ] : loaded) {
        if (counts.first > score_right_now) {
            cout << "impossible" << endl;
            return 0;
        }
        score_right_now -= counts.first + counts.second;
        loaded_result_builder.push_back(index);
    }

    if (score_right_now + net_closers != 0) {
        cout << "impossible" << endl;
        return 0;
    }

    for (int index : balanced) cout << index + 1 << endl;
    for (int index : all_openers) cout << index + 1 << endl;
    for (int index : loaded_result_builder) cout << index + 1 << endl;
    for (int index : all_closers) cout << index + 1 << endl;

    return 0;
}
