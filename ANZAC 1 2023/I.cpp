#include <iostream>
#include <vector>

using namespace std;

int main() {
    size_t rows, cols;
    cin >>  rows >> cols;

    vector<vector<size_t>> sculpture(rows, vector<size_t>(cols));
    vector<vector<size_t>> output(rows, vector<size_t>(cols));

    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++) {
            size_t d;
            cin >> d;
            sculpture[i][j] = d;
        }

    for (size_t i = 1; i < rows - 1; i++)
        for (size_t j = 1; j < cols - 1; j++) {
            size_t d = sculpture[i][j];
            if (d < sculpture[i-1][j] && d < sculpture[i+1][j] && d < sculpture[i][j-1] && d < sculpture[i][j+1])
                output[i][j] = 1;
        }

    for (const auto& s : output) {
        for  (const auto& q : s) cout << q << " ";
        cout << endl;
    }

    return 0;
}
