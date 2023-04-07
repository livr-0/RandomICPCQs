#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

map<int, double> chances = {
    { 2, 1.0/36 }, { 3, 2.0/36 }, { 4, 3.0/36 },
    { 5, 4.0/36 }, { 6, 5.0/36 }, { 7, 6.0/36 },
    { 8, 5.0/36 }, { 9, 4.0/36 }, { 10, 3.0/36 },
    { 11, 2.0/36 }, { 12, 1.0/36 }
};

set<string> getWays(string s, int d) {
    set<string> ways;
    for (size_t i = 0; i < s.length(); i++) {
        int v = s[i] - 48;
        if (v > d) break;
        string t = s;
        t.erase(i, 1);
        if (v == d) ways.insert(t);
        else {
            set<string> w = getWays(t, d - v);
            for (const string& q : w) ways.insert(q);
        }
    }
    return ways;
}

double getScore(string s, bool maximiser) {
    if (s == "") return 0.0;
    double score = 0.0, d = (double)(stoi(s));
    for (int i = 2; i <= 12; i++) {
        set<string> ways = getWays(s, i);
        if (ways.empty()) score += chances[i] * d;
        else if (maximiser) {
            double maxScore = 0.0;
            for (const string& way : ways) {
                double localScore = getScore(way, maximiser);
                if (maxScore < localScore) maxScore = localScore;
            }
            score += maxScore * chances[i];
        }
        else {
            double minScore = 1e8;
            for (const string& way : ways) {
                double localScore = getScore(way, maximiser);
                if (minScore > localScore) minScore = localScore;
            }
            score += minScore * chances[i];
        }
    }
    return score;
}

string sDiff(string s, string t) {
    string res = "";
    size_t i = 0, j = 0;
    while (i < s.length()) {
        if (j >= t.length()) {
            for (; i < s.length(); i++) res += s[i];
            break;
        }
        if (s[i] == t[j]) { i++; j++; }
        else res += s[i++];
    }
    return res;
}

void solve(string s, int d) {
    set<string> ways = getWays(s, d);
    if (ways.empty()) {
        cout << "-1 " << (double)(stoi(s)) << endl;
        cout << "-1 " << (double)(stoi(s)) << endl;
        return;
    }
    double maxScore = -1.0, minScore = 1e8;
    string maxVal, minVal;
    for (const string& way : ways) {
        double localMaxScore = getScore(way, 1);
        double localMinScore = getScore(way, 0);
        if (localMaxScore > maxScore) {
            maxScore = localMaxScore;
            maxVal = way;
        }
        if (localMinScore < minScore) {
            minScore = localMinScore;
            minVal = way;
        }
    }
    cout << sDiff(s, minVal) << " " << minScore << endl;
    cout << sDiff(s, maxVal) << " " << maxScore << endl;
}

int main() {
    string s;
    int d, d1, d2;
    cin >> s >> d1 >> d2;
    d = d1 + d2;
    cout.precision(5);
    cout << fixed;
    solve(s, d);
    return 0;
}
