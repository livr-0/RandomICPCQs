#include <iostream>
#include <vector>

using namespace std;

int main() {
    size_t r, c;
    cin  >> r >> c;
    vector<string> v;
    while (r--) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    size_t maxP = 0, localP = 0;
    for (size_t i = 0; i < c; i++) {
        bool allMatch = true;
        char c = v[0][i];
        for (size_t j = 0; j < v.size(); j++) {
            if (v[j][i] != c) {
                allMatch = false;
                break;
            }
        }
        if (allMatch) {
            localP++;
        }
        else {
            if (localP > maxP) maxP = localP;
            localP = 0;
        }
    }
    if (localP > maxP) maxP = localP;
    cout << maxP << endl;
    return 0;
}
