#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    size_t n, k;
    cin >> n >> k;
    vector<pair<size_t, size_t>> shows(n); // { endTime, startTime }
    multiset<size_t, greater<size_t>> reels; // { endTime }
    for (size_t i = 0; i < n; i++) cin >> shows[i].second >> shows[i].first;
    sort(shows.begin(), shows.end());
    size_t c = 0;
    for (size_t i = 0; i < n; i++) {
        auto it = reels.lower_bound(shows[i].second);
        if (it != reels.end()) reels.erase(it);
        if (reels.size() < k) {
            c++;
            reels.insert(shows[i].first);
        }
    }
    cout << c << endl;
    return 0;
}
