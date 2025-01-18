#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    int n, min_index = 1, max_count = 0;
    cin >> n;

    vector<pair<char, int>> v(n);
    unordered_map<int, int> running_count, smallest_count, net_count;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v[i].first = s[0];
        s.erase(s.begin());
        v[i].second = stoi(s);
    }

    for (int i = 0; i < n; i++) {
        net_count[v[i].second]++;
        v[i].first == 's' ? running_count[v[i].second]++ : running_count[v[i].second]--;
        smallest_count[v[i].second] = min(smallest_count[v[i].second], running_count[v[i].second]);
    }


    for (auto& [id, count] : net_count)
        if (count > 0 && smallest_count[id] == 0 && running_count[id] == 0)
            max_count++;

    int temp_count = max_count;
    for (int i = 0; i < n - 1; i++) {
        if (running_count[v[i].second] != 0) continue;

        if (v[i].first == 's') {
            if (smallest_count[v[i].second] == 0) temp_count--;
            smallest_count[v[i].second]--;
        } else {
            if (smallest_count[v[i].second] == -1) temp_count++;
            smallest_count[v[i].second]++;
            if (temp_count > max_count) {
                max_count = temp_count;
                min_index = i + 2;
            }
        }
    }

    cout << min_index << " " << max_count << endl;

    return 0;
}
