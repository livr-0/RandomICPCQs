#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<char, size_t> letters;
    string s;
    cin >> s;
    for (const char& c : s) letters[c]++;
    size_t res = 0;
    while (letters.size() > 2) {
        size_t minCount = 101;
        char minLetter;
        for (const auto& l : letters) {
            if (l.second < minCount) {
                minCount = l.second;
                minLetter = l.first;
            }
        }
        res += minCount;
        letters.erase(minLetter);
    }
    cout << res << endl;
    return 0;
}
