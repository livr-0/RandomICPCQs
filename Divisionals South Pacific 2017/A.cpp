#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, double> weights;

    size_t n;
    cin >> n;

    while (n--) {
        string s;
        double d;
        cin >> s >> d;
        weights[s] = d;
    }

    string s;
    cin >> s;

    double res = 0.0;

    string compoundName = "";
    size_t compoundSize = 0;
    char c = '9';
    for (const char& c : s) {
        if (c >= 65 && c <= 90) {
            if (compoundName != "") {
                if (compoundSize == 0) compoundSize = 1;
                res += weights[compoundName] * compoundSize;
                compoundName = "";
                compoundSize = 0;
            }
            compoundName = c;
        }
        else if (c >= 48 && c <= 57) {
            compoundSize *= 10;
            compoundSize += c - 48;
        }
        else compoundName += c;
    }
    if (compoundSize == 0) compoundSize = 1;
    res += weights[compoundName] * compoundSize;

    cout.precision(6);
    cout << fixed << res << endl;
    return 0;
}
