#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, string> strs, strsre;
    size_t n, k; cin >> n >> k;
    size_t lim = n - k;
    string str1, str2;
    while (lim--) {
        cin >> str1 >> str2;
        strs.emplace(str1, str2);
        strsre.emplace(str2, str1);
    }

    string half1, half2;
    string mid = strs.begin()->first;
    half2 += mid;
    string end1;
    while (true) {
        if (half1.size() + half2.size() == n) break;
        half2 += strs[mid].back();
        if (strs.find(mid) == strs.end()) {
            end1 = half2.substr(0, k - 1);
            break;
        }
        mid = strs[mid];
    }

    if (!end1.empty() && strsre.find(end1) != strsre.end()) {
        string curre = end1;
        half1 += strsre[curre];
        while (strsre.find(curre) != strsre.end()) {
            if (half1.size() + half2.size() == n) break;
            half1 = curre[0] + half1;
            curre = strsre[curre];
        }
    }

    cout << half1 << half2 << endl;
    return 0;
}
