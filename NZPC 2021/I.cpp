#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

unordered_map<string, unordered_set<string>> tree;

long getGCD(long a, long b) {
    if (!a) return b;
    if (!b) return a;
    if (a < b) return getGCD(a, b % a);
    return getGCD(b, a % b);
}

string toFrac(double val) {
    double intPart = floor(val);
    double fracPart = val - intPart;

    long precision = 1e9;
    long gcd = getGCD(round(fracPart * precision), precision);

    long denomenator = precision / gcd;
    long numerator = round(fracPart * precision) / gcd;

    return to_string(numerator) + "/" + to_string(denomenator);
}

double doRec(string start, string end) {
    if (start == end) return 1;
    double res = 0;
    for (const string& parent : tree[start]) res += doRec(parent, end)/2;
    return res;
}

void solveProblem(string name1, string name2) {
    double getVal = doRec(name1, name2);
    if (getVal <= 1e-5) {
        double getVal = doRec(name2, name1);
        if (getVal <= 1e-5) cout << name1 << " and " << name2 << " are not related." << endl;
        else cout << name2 << " is " << toFrac(getVal) << " " << name1 << "." << endl;
    } else cout << name1 << " is " << toFrac(getVal) << " " << name2 << "." << endl;
}

int main() {
    string name1, name2, name3;
    while (true) {
        cin >> name1;
        while (name1 != "#") {
            cin >> name2 >> name3;
            tree[name1].insert(name2);
            tree[name1].insert(name3);
            cin >> name1;
        }
        if (tree.empty()) break;
        string query1, query2;
        cin >> query1;
        while (query1 != "#") {
            cin >> query2;
            solveProblem(query1, query2);
            cin >> query1;
        }
        cout << endl;
        tree.clear();
    }
    return 0;
}
