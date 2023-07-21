#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

void merge(unordered_map<size_t, size_t>& table, vector<size_t>& out, vector<size_t>& left, vector<size_t>& right) {
    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] > right[j]) {
            table[right[j]] += (left.size() - i);
            out[k++] = right[j++];
        }
        else {
            out[k++] = left[i++];
        }
    }
    while(i < left.size()) {
        out[k++] = left[i++];
    }
    while(j < right.size()) {
        out[k++] = right[j++];
    }

}

void mergeSort(unordered_map<size_t, size_t>& table, vector<size_t>& in) {
    if (in.size() == 1) return;
    vector<size_t> left(in.begin(), in.begin() + in.size() / 2);
    mergeSort(table, left);
    vector<size_t> right(in.begin() + in.size() / 2, in.end());
    mergeSort(table, right);
    merge(table, in, left, right);
}

int main() {
    size_t n;
    cin >> n;
    unordered_map<size_t, size_t> table;
    vector<size_t> list;
    size_t s;
    for(size_t i = 0; i < n; i++) {
        cin >> s;
        list.push_back(s);
        table.emplace(s, 0);
    }

    mergeSort(table, list);
    vector<size_t> counts;
    for (auto& t : table) {
        counts.push_back(t.second);
    }
    sort(counts.begin(), counts.end());

    vector<size_t> swaps;
    size_t sub = 0;
    for(size_t i = 0; i < n; i++) {
        if (counts[i] == 0) {
            if (sub > 0) break;
            continue;
        }
        while (counts[i] > sub) {
            swaps.push_back(n - i);
            sub++;
        }
    }

    cout << sub << endl;
    for (auto& s : swaps) {
        cout << s << endl;
    }

    return 0;
}
