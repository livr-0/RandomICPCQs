#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    size_t n;
    cin >> n;
    size_t s;
    vector<size_t> sortNeeded;

    for (size_t i = 0; i < n; i++) {
        cin >> s;
        sortNeeded.push_back(s);
    }

    size_t tCount = 0;
    vector<size_t> sCounts;
    size_t sCount = 0;

    while (n--) {
        for (size_t i = 0; i < sortNeeded.size() - 1; i++) {
            if (sortNeeded[i] > sortNeeded[i+1]) {
                swap(sortNeeded[i], sortNeeded[i+1]);
                sCount++;
            }
        }

        if (sCount > 0) {
            sCounts.push_back(sCount);
            sCount = 0;
            tCount++;
        }
        else {
            break;
        }
    }

    cout << tCount << '\n';

    for (auto& s : sCounts) {
        cout << s << '\n';
    }
}
