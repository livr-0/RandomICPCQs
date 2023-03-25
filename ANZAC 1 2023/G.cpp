#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    size_t n, k;
    cin >> n >> k;
    size_t actual_rot = n - k;

    vector<long long> vector1;
    vector<long long> vector2;
    long long m;

    cin >> m;
    for (long long j = 0; j < m; j++) {
        long long a;
        cin >> a;
        vector1.push_back(a);
    }

    cin >> m;
    for (long long j = 0; j < m; j++) {
        long long a;
        cin >> a;
        vector2.push_back(a);
    }

    vector<long long> sum;
    size_t i1 = 0, i2 = 0;
    while (i1 < vector1.size() && i2 < vector2.size()) {
        if (abs(vector1[i1]) == abs(vector2[i2])) {
            if (vector1[i1] == vector2[i2]) sum.push_back(vector1[i1]);
            i1++; i2++;
        }
        else if (abs(vector1[i1]) < abs(vector2[i2])) {
            sum.push_back(vector1[i1]);
            i1++;
        }
        else if (abs(vector1[i1]) > abs(vector2[i2])) {
            sum.push_back(vector2[i2]);
            i2++;
        }
    }
    if (i1 < vector1.size()) sum.insert(sum.end(), vector1.begin() + i1, vector1.end());
    if (i2 < vector2.size()) sum.insert(sum.end(), vector2.begin() + i2, vector2.end());
    cout << sum.size();
    for (const long long a : sum) cout << " " << a;
    cout << endl;

    vector<long long> prod;
    i1 = 0, i2 = 0;
    while (i1 < vector1.size() && i2 < vector2.size()) {
        if (abs(vector1[i1]) == abs(vector2[i2])) {
            if (vector1[i1] == vector2[i2]) prod.push_back(abs(vector1[i1]));
            else prod.push_back(-abs(vector1[i1]));
            i1++; i2++;
        }
        else if (abs(vector1[i1]) < abs(vector2[i2])) i1++;
        else if (abs(vector1[i1]) > abs(vector2[i2])) i2++;
    }
    cout << prod.size();
    for (const long long a : prod) cout << " " << a;
    cout << endl;

    vector<long long> rot1;
    for (const long long a : vector1) {
        long long sign = a > 0 ? 1 : -1;
        rot1.push_back(((abs(a) + actual_rot - 1) % n + 1) * sign);
    }
    sort(rot1.begin(), rot1.end(), [](auto a, auto b){ return abs(a) < abs(b); });
    cout << rot1.size();
    for (const long long a : rot1) cout << " " << a;
    cout << endl;

    vector<long long> rot2;
    for (const long long a : vector2) {
        long long sign = a > 0 ? 1 : -1;
        rot2.push_back(((abs(a) + actual_rot - 1) % n + 1) * sign);
    }
    sort(rot2.begin(), rot2.end(), [](auto a, auto b){ return abs(a) < abs(b); });
    cout << rot2.size();
    for (const long long a : rot2) cout << " " << a;
    cout << endl;
}
