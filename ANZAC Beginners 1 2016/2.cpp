#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    set<size_t> indices = { 0, 1, 2, 3, 4, 5 };
    vector<size_t> v;
    for (size_t i = 0; i < 6; i++) {
        size_t value;
        cin >> value;
        v.push_back(value);
    }
    size_t sum1, sum2;
    cin >> sum1 >> sum2;
    for (size_t i = 1; i < 5; i++) {
        for (size_t j = i + 1; j < 6; j++) {
            if (v[0] + v[i] + v[j] == sum1) {
                set<size_t, greater<int>> box1, box2;
                box1.insert(v[0]); box1.insert(v[i]); box1.insert(v[j]);
                indices.erase(0); indices.erase(i); indices.erase(j);
                for (const size_t& index : indices) box2.insert(v[index]);
                for (const size_t& val : box1) cout << val << " ";
                for (const size_t& val : box2) cout << val << " ";
                cout << endl;
                return 0;
            }
            else if (v[0] + v[i] + v[j] == sum2) {
                set<size_t, greater<int>> box1, box2;
                box1.insert(v[0]); box1.insert(v[i]); box1.insert(v[j]);
                indices.erase(0); indices.erase(i); indices.erase(j);
                for (const size_t& index : indices) box2.insert(v[index]);
                for (const size_t& val : box2) cout << val << " ";
                for (const size_t& val : box1) cout << val << " ";
                cout << endl;
                return 0;
            }
        }
    }
    return 0;
}
