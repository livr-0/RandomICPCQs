#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> scores;
    while (n--) {
        string s;
        int c, r = 0;
        cin >> s >> c;
        while (c--) {
            char x, y, z;
            cin >> x >> y >> z;
            if (x == 'Y' && y == 'Y' && z == 'Y') r++;
            else if (x == 'Y' && z == 'Y') r++;
            else if (x == 'N' && z == 'N') r++;
        }
        scores[s] = r;
    }
    int bestScore = -1;
    string bestMovie = "";
    for (const auto& score : scores) {
        if (score.second > bestScore) {
            bestScore = score.second;
            bestMovie = score.first;
        }
    }
    cout << bestMovie << endl;
    return 0;
}
