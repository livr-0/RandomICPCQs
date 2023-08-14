#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void makeVector(vector<string>& vec, string s) {
    string temp = "";
    for (const char& c : s) {
        if (c == ' ' || c == '+') {
            if (temp != "") {
                vec.push_back(temp);
                temp = "";
            }
        } else temp += c;
    }
    if (temp != "") vec.push_back(temp);
}

void makeMap(map<string, int>& mp, vector<string>& vec) {
    for (const string& s : vec) {
        bool multiplying = 1;
        int multiplier = 0;
        int molMultiplier = 0;
        string mol = "";
        for (const char& c : s) {
            if (multiplying) {
                if (isdigit(c)) {
                    multiplier *= 10;
                    multiplier += c - '0';
                } else {
                    multiplying = 0;
                    if (!multiplier) multiplier = 1;
                }
            }
            if (!multiplying) {
                if (isdigit(c)) {
                    molMultiplier *= 10;
                    molMultiplier += c - '0';
                } else {
                    if (c >= 'A' && c <= 'Z') {
                        if (mol != "") {
                            if (!molMultiplier) molMultiplier = 1;
                            mp[mol] += multiplier * molMultiplier;
                        }
                        mol = "";
                        molMultiplier = 0;
                    }
                    mol += c;
                }
            }
        }
        if (mol != "") {
            if (!molMultiplier) molMultiplier = 1;
            mp[mol] += multiplier * molMultiplier;
        }
    }
}

void diff(map<string, int>& left, map<string, int>& right, int t) {
    map<string, int> diffs;
    for (const auto& l : left)
        if (right[l.first] != l.second)
            diffs[l.first] = l.second - right[l.first];
    for (const auto& r : right)
        if (!diffs.count(r.first) && left[r.first] != r.second)
            diffs[r.first] = left[r.first] - r.second;
    if (diffs.empty()) cout << "Equation " << t << " is balanced." << endl;
    else {
        cout << "Equation " << t << " is unbalanced." << endl;
        for (const auto& d : diffs)
            cout << "You have " << ((d.second < 0) ? "created " : "destroyed ") <<
                abs(d.second) << " atom" << ((abs(d.second) == 1) ? " " : "s ") <<
                "of " << d.first << "." << endl;
        cout << endl;
    }
}

int main() {
    int t = 1;
    while (1) {
        map<string, int> mLeft, mRight;
        vector<string> left, right;

        string s;
        getline(cin, s);
        if (s == "#") break;
        stringstream ss(s);

        getline(ss, s, '=');
        makeVector(left, s);

        getline(ss, s);
        makeVector(right, s);

        makeMap(mLeft, left);
        makeMap(mRight, right);

        diff(mLeft, mRight, t++);
    }
    return 0;
}
