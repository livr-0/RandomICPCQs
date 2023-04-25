#include <iostream>
#include <set>

using namespace std;

int main() {
    set<pair<string, string>> names;
    size_t n;
    cin >> n;
    while (n--) {
        string fName, lName;
        cin >> fName >> lName;
        names.insert({lName, fName});
    }
    for (const auto& name : names) cout << name.second << " " << name.first << endl;
    return 0;
}
