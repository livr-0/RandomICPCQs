#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> image, desert;

void maker(bool d) {
    size_t rows, cols;
    cin >> rows >> cols;
    while (rows-- > 0) {
        vector<bool> col;
        string s;
        cin >> s;
        for (const char& c : s) col.push_back(c == '#');
        d ? desert.push_back(col) : image.push_back(col);
    }
}

size_t impose() {
    size_t res = 0;
    size_t dRow = 0, dCol = 0;
    while (1) {
        bool broken = false;
        for (size_t i = 0; i < image.size(); i++) {
            for (size_t j = 0; j < image[0].size(); j++) {
                if (image[i][j] && image[i][j] != desert[dRow+i][dCol+j]) {
                    broken = true;
                    break;
                }
            }
            if (broken) break;
        }
        if (!broken) res++;
        dCol++;
        if (dCol > desert[0].size() - image[0].size()) {
            dCol = 0;
            dRow++;
        }
        if (dRow > desert.size() - image.size()) break;
    }
    return res;
}

int main() {
    maker(0);
    maker(1);
    if (desert.size() < image.size() || desert[0].size() < image[0].size()) cout << 0 << endl;
    else cout << impose() << endl;
    return 0;
}
