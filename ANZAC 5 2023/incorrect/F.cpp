#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

int main() {
    size_t n;
    cin >> n;
    vector<string> names;
    string name;
    while (n--) {
        cin >> name;
        names.push_back(name);
    }
    unordered_map<string, size_t> votes;
    for (auto& n : names) {
        if (votes.find(n) == votes.end()) {
            votes.emplace(n, 1);
        }
        else {
            votes[n]++;
        }
    }
    map<size_t, set<string>> stuff;
    for (auto& v : votes) {
        if (stuff.find(v.second) == stuff.end()) {
            set<string> sth;
            sth.insert(v.first);
            stuff.emplace(v.second, sth);
        }
        else {
            stuff[v.second].insert(v.first);
        }
    }
    auto it = stuff.rbegin();
    if (it->second.size() > 1) {
        cout << "Tie between ";
        auto it2 = it->second.begin();
        for (; it2 != --it->second.end(); it2++) {
            cout << (*it2) << ", ";
        }
        cout << (*it2) << '.' << endl;
    }
    else {
        size_t major = (*it).first;
        cout << (*it->second.begin()) << " won by ";
        size_t major2 = (++it)->first;
        if (major - major2 > 1) cout << (major - major2) << " votes." << endl;
        else cout << 1 << "vote." << endl;
    }
    return 0;
}