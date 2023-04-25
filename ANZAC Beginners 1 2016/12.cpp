#include <bits/stdc++.h>

using namespace std;

struct Triangle {
    size_t s1, s2, s3;
    Triangle() {}
    Triangle(size_t s, size_t p, size_t d) : s1(s), s2(p), s3(d) {}
    bool operator<(Triangle& o) {
        tuple<size_t, size_t, size_t> t1 = { s1, s2, s3 };
        tuple<size_t, size_t, size_t> t2 = { o.s1, o.s2, o.s3 };
        return t1 < t2;
    }
};

vector<vector<Triangle>> triangles;

size_t m = 0;

size_t getVal(vector<Triangle> ts) {
    size_t res = 0;
    sort(ts.begin(), ts.end());
    do {
        bool broken = 0;
        for (size_t i = 0; i < 6; i++) {
            if (i == 5 && ts[5].s3 != ts[0].s1) {
                broken = 1;
                break;
            }
            else if (i != 5 && ts[i].s3 != ts[i + 1].s1) {
                broken = 1;
                break;
            }
        }
        if (!broken) {
            size_t lRes = 0;
            for (size_t i = 0; i < 6; i++) lRes += ts[i].s2;
            if (lRes > res) res = lRes;
        }
    } while (next_permutation(ts.begin(), ts.end()));
    return res;
}

int main() {
    for (size_t i = 0; i < 6; i++) {
        size_t s, p, d;
        cin >> s >> p >> d;
        vector<Triangle> v;
        v.push_back({ s, p, d });
        v.push_back({ d, s, p });
        v.push_back({ p, d, s });
        triangles.push_back(v);
    }
    size_t maxVal = 0;
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            for (size_t k = 0; k < 3; k++)
                for (size_t l = 0; l < 3; l++)
                    for (size_t m = 0; m < 3; m++)
                        for (size_t n = 0; n < 3; n++) {
                            size_t val = getVal({
                                triangles[0][i],
                                triangles[1][j],
                                triangles[2][k],
                                triangles[3][l],
                                triangles[4][m],
                                triangles[5][n]
                            });
                            if (val > maxVal) maxVal = val;
                        }
    if (!maxVal) cout << "none" << endl;
    else cout << maxVal << endl;
    return 0;
}
