#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    size_t n;
    cin >> n;
    map<string, int> m;
    while (n--) {
        string s;
        cin >> s;
        m[s]++;
    }
    int max1 = 0, max2 = 0;
    for (const auto & a : m) {
        if (a.second > max1) {
            max2 = max1;
            max1 = a.second;
        }
    }
    set<string> winners;
    for (const auto& a : m) {
        if (a.second == max1) winners.insert(a.first);
    }
    if (winners.size() == 1) {
        cout << (*winners.begin()) << " won by " << max1 - max2 << " vote";
        if (max1 - max2 > 1) cout << "s";
        cout << "." << endl;
    }
    else {
        cout << "Tie between ";
        for (const auto& winner : winners) {
            cout << winner;
            if (winners.find(winner) == (--winners.end())) cout << ".";
            else cout << ", ";
        }
        cout << endl;
    }
    return 0;
}
