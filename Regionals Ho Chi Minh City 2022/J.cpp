#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;

typedef unordered_map<char, vector<size_t>> lookup;

size_t rec(lookup r, char c, size_t lp, vector<int>& memoized) {
    if (memoized[lp] == -1) {
        size_t res = 0;
        if (c == 'I') {
            for (const size_t& p : r['C'])
                if (p > lp + 1)
                    res += rec(r, 'C', p, memoized);
        }
        else if (c == 'C') {
            for (const size_t& p : r['P'])
                if (p > lp + 1)
                    res += rec(r, 'P', p, memoized);
        }
        else {
            for (const size_t& p : r['C'])
                if (p > lp + 1)
                    res++;
        }
        memoized[lp] = res;
    }
    return memoized[lp];
}

int main() {
    string s;
    while (cin >> s) {
        lookup r;
        vector<int> memoized(s.size(), -1);

        for (size_t i = 0; i < s.length(); i++)
            if (s[i] == 'I' || s[i] == 'C' || s[i] == 'P')
                r[s[i]].push_back(i);

        size_t res = 0;
        for (const size_t& p : r['I']) res += rec(r, 'I', p, memoized);
        cout << res << endl;
    }
    return 0;
}
