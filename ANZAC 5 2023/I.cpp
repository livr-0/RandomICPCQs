#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

multiset<size_t> valueCounts; // count of each value
map<size_t, set<size_t>> valuesGrouped; // mode basically
map<size_t, size_t> indexedValues; // create some unique index for every value
map<size_t, size_t> reversedIndexedValues;
vector<size_t> values;
set<size_t> uniqueValues; // types of values
vector<pair<size_t, vector<bool>>> table; // the table

void solveThisForMe(int value, int mode) {
    for (int i = 0; i < table.size(); i++) {
        if (!mode) break;
        if (table[i].second[indexedValues[value]]) continue;
        table[i].second[indexedValues[value]] = 1;
        table[i].first++;
        mode--;
    }
    sort(table.begin(), table.end(), [](auto &a, auto &b) { return a.first < b.first; });
}

void printTable() {
    for (const auto& row : table) {
        for (int i = 0; i < row.second.size(); i++) {
            if (row.second[i])
                cout << reversedIndexedValues[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    size_t n;
    cin >> n;
    while (n--) {
        size_t x;
        cin >> x;
        uniqueValues.insert(x);
        values.push_back(x);
    }
    sort(values.begin(), values.end());
    for (const size_t& x : values) {
        if (valueCounts.find(x) == valueCounts.end()) {
            indexedValues[x] = indexedValues.size();
            reversedIndexedValues[indexedValues[x]] = x;
        }
        valueCounts.insert(x);
    }
    for (const size_t& uv : uniqueValues) {
        valuesGrouped[valueCounts.count(uv)].insert(uv);
    }
    table = vector<pair<size_t, vector<bool>>>((*valuesGrouped.rbegin()).first, {0, vector<bool>(indexedValues.size(), 0)});
    cout << (*valuesGrouped.rbegin()).first << endl;
    while (!valuesGrouped.empty()) {
        size_t mode = (*valuesGrouped.rbegin()).first;
        size_t aValue = (*(*valuesGrouped.rbegin()).second.begin());
        (*valuesGrouped.rbegin()).second.erase(aValue);
        if ((*valuesGrouped.rbegin()).second.empty()) {
            valuesGrouped.erase((*valuesGrouped.rbegin()).first);
        }
        solveThisForMe(aValue, mode);
    }
    printTable();
    return 0;
}
