#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    int remaining = n - 2, changes_counter = 0;
    vector<pair<int, int>> c(n);
    vector<int> d(n, 1);
    vector<bool> seen(n, false);

    for (int i = 0; i < n; i++) c[i].second = i;

    for (int i = 0; i < l; i++) {
        int u, v;
        cin >> u >> v;
        c[u].first++;
        c[v].first++;
    }
    sort(c.begin(), c.end());

    for (int i = 0; remaining > 0 && i < n; i++)
        if (c[i].first > 1) {
            if (c[i].first - 1 <= remaining) {
                d[c[i].second] = c[i].first;
                remaining -= (c[i].first - 1);
            } else {
                d[c[i].second] = remaining + 1;
                remaining = 0;
            }
        }

    for (int i = 0; i < n; i++)
        if (c[i].first != d[c[i].second])
            changes_counter++;

    for (int i = 0; i < n; i++) {
        c[i].first = d[i];
        c[i].second = i;
    }
    sort(c.begin(), c.end(), greater());


    cout << changes_counter << endl << n << " " << n - 1 << endl;

    for (int i = 0; i < n; i++)
        if (c[i].first > 0) {
            int limit_value = c[i].first;
            for (int j = 1; j <= limit_value; j++)
                if (seen[i + j]) {
                    limit_value++;
                } else {
                    seen[i + j] = true;
                    c[i + j].first--;
                    cout << c[i].second << " " << c[i + j].second << endl;
                }
        }

    return 0;
}
