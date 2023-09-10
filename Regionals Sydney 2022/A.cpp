#include <iostream>
#include <vector>

using namespace std;

vector<int> computePrefixFunction(string& w) {
    int m = w.size(), k = 0;
    vector<int> prefix(m);
    for (int i = 1; i < m; i++) {
        while (k > 0 && w[k] != w[i]) k = prefix[k - 1];
        if (w[k] == w[i]) k++;
        prefix[i] = k;
    }
    return prefix;
}

int kmp(string& text, string& pattern, vector<int>& prefix) {
    int result = 0, n = text.size(), m = pattern.size(), q = 0;
    for (int i = 0; i < n; i++) {
        while (q > 0 && pattern[q] != text[i]) q = prefix[q - 1];
        if (pattern[q] == text[i]) q++;
        if (q == m) {
            result++;
            q = prefix[q - 1];
        }
    }
    return result;
}

int main() {
    int k;
    string s, j;
    cin >> k >> s >> j;
    vector<int> T = computePrefixFunction(j);
    vector<string> strings(k + 1);
    for (int i = 0; i <= k; i++)
        for (int l = 0; l < s.size(); l += i + 1)
            strings[i] += s[l];
    for (auto& st : strings) cout << kmp(st, j, T) << endl;
    return 0;
}
