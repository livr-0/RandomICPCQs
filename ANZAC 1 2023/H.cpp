#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    vector<vector<int>> floor, rowPartialSums, finalPartialSums;

    for (int i = 0; i < n; i++) {
        vector<int> row;
        string rowStr;
        cin >> rowStr;
        for (const char &c : rowStr) row.push_back(c == 'D');
        floor.push_back(row);
    }

    for (int r = 0; r < n; r++) {
        const auto &row = floor[r];
        vector<int> partialSums;
        int first = 0;
        for (int i = 0; i < s; i++) first += row[i];
        partialSums.push_back(first);
        for (int i = 0; i < n - s; i++)
            partialSums.push_back(partialSums[i] - row[i] + row[i + s]);
        rowPartialSums.push_back(partialSums);
    }

    vector<int> first;
    for (int i = 0; i < n - s + 1; i++) {
        int count = 0;
        for (int j = 0; j < s; j++) count += rowPartialSums[j][i];
        first.push_back(count);
    }

    finalPartialSums.push_back(first);
    for (int i = 0; i < n - s; i++) {
        vector<int> partialSums;
        for (int c = 0; c < n - s + 1; c++)
            partialSums.push_back(finalPartialSums[i][c] - rowPartialSums[i][c] + rowPartialSums[i + s][c]);
        finalPartialSums.push_back(partialSums);
    }

    map<int, size_t> counts;
    for (const auto &r : finalPartialSums)
        for (const auto &c : r)
            counts[c]++;

    for (const auto &item : counts)
        cout << item.first << " " << item.second << endl;

    return 0;
}
