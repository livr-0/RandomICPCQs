#include <bits/stdc++.h>

using namespace std;

void printRes(int i, int j, int k, int res) {
    char a, b, c;
    if (i == 0) a = '-';
    else if (i == 1) a = '+';
    else if (i == 2) a = '*';
    else a = '/';
    if (j == 0) b = '-';
    else if (j == 1) b = '+';
    else if (j == 2) b = '*';
    else b = '/';
    if (k == 0) c = '-';
    else if (k == 1) c = '+';
    else if (k == 2) c = '*';
    else c = '/';
    cout << "4 " << a << " 4 " << b << " 4 " << c << " 4 = " << res << endl;
}

int getResult(int i, int j, int k) {
    vector<int> vals = { 4, 4, 4, 4 };
    vector<pair<int, int>> ops = { { i, 0 }, { j, -1 }, { k, -2 } };
    sort(ops.begin(), ops.end());
    while (ops.size()) {
        int op = ops[ops.size() - 1].first;
        int pos = -ops[ops.size() - 1].second;
        ops.pop_back();
        if (op == 0) vals[pos] -= vals[pos + 1];
        else if (op == 1) vals[pos] += vals[pos + 1];
        else if (op == 2) vals[pos] *= vals[pos + 1];
        else vals[pos] /= vals[pos + 1];
        vals.erase(vals.begin() + pos + 1);
        for (size_t i = 0; i < ops.size(); i++) {
            int nPos = -ops[i].second;
            if (nPos > pos) nPos--;
            ops[i].second = -nPos;
        }
    }
    return vals[0];
}

void solve() {
    int x;
    cin >> x;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++) {
                int res = getResult(i, j, k);
                if (res == x) {
                    printRes(i, j, k, res);
                    return;
                }
            }
    cout << "no solution" << endl;
}

int main() {
    int x;
    cin >> x;
    while (x--) solve();
    return 0;
}
