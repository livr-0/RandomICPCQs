#include <iostream>
#include <set>

using namespace std;

int main() {
    set<char> chars;
    size_t n, k, res = 0;
    cin >> n >> k;
    while (n--) {
        string s;
        cin >> s;
        for (const char& c : s) if (c - 64 <= k) chars.insert(c);
        if (chars.size() == s.length()) res++;
        chars.clear();
    }
    cout << res << endl;
    return 0;
}
