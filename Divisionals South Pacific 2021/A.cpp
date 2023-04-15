#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<pair<string, bool>> um;
    size_t n, c = 0;
    cin >> n;
    while (n--) {
        string s1, s2;
        cin >> s1 >> s2;
        bool b = (s2 == "yes");
        um.push_back({ s1, b });
        if (b) c++;
    }
    for (const auto& u : um) {
        cout << u.first << " ";
        if (u.second) cout << um.size() - c;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
