#include <iostream>
#include <vector>

using namespace std;

struct Mod {
    char mod;
    int x1, x2;
};

int main() {
    int landSize, modCount;
    cin >> landSize >> modCount;
    vector<int> d2(landSize + 2);
    for (int i = 0; i < modCount; i++) {
        string type;
        int x1, x2;
        cin >> type >> x1 >> x2;

        switch (type[0]) {
            case 'R':
                d2[x1 - 1]++;
                d2[x1]--;
                d2[x2]--;
                d2[x2 + 1]++;
                break;
            case 'D':
                d2[x1 - 1]--;
                d2[x1]++;
                d2[x2]++;
                d2[x2 + 1]--;
                break;
            case 'H':
                d2[x1 - 1]++;
                d2[x2 + 1]++;
                d2[(x1 + x2) / 2]--;
                d2[(x1 + x2 + 1) / 2]--;
                break;
            case 'V':
                d2[x1 - 1]--;
                d2[x2 + 1]--;
                d2[(x1 + x2) / 2]++;
                d2[(x1 + x2 + 1) / 2]++;
                break;
        }
    }

    vector<int> d1(landSize + 1);
    d1[0] = d2[0];
    for (int i = 1; i < landSize; i++) {
        d1[i] = d1[i - 1] + d2[i];
    }

    vector<int> d(landSize);
    d[0] = d1[0];
    for (int i = 1; i < landSize; i++) {
        d[i] = d[i - 1] + d1[i];
    }

    for (auto x : d) {
        cout << x << "\n";
    }
}
