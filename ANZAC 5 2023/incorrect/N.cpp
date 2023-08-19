#include <iostream>
#include <vector>

using namespace std;

int main() {
    int l, r;
    cin >> l >> r;
    int n = (r - l) / 2 + 1;
    vector<size_t> heights;
    size_t height;
    while (n--) {
        cin >> height;
        heights.push_back(height);
    }

    size_t left, right;
    int li = l;
    int i = 0;
    while (li < -1) {
        li += 2;
        i++;
    }
    left = heights[i];
    int j = i + 1;
    right = heights[j];
    
    size_t result;
    if (left < right) {
        result = left * 2;
    }
    else {
        result = right * 2;
    }

    while ((i > 0 && j < heights.size() - 1) || ((i == 0 || j == heights.size() - 1) && result < max(left, right) * (j - i) * 2)) {
        if (left < right) {
            i--;
            if (heights[i] > left) {
                if (heights[i] > right) {
                    result = right * (j - i) * 2;
                }
                else {
                    result = heights[i] * (j - i) * 2;
                }
            }
            else {
                result += heights[i] * 2;
            }
            left = heights[i]; 
        }
        else if (right < left) {
            j++;
            if (heights[j] > right) {
                if (heights[j] > left) {
                    result = left * (j - i) * 2;
                }
                else {
                    result = heights[j] * (j - i) * 2;
                }
            }
            else {
                result += heights[j] * 2;
            }
            right = heights[j];
        }
        else {
            i--; j++;
            if (heights[i] > left && heights[j] > right) {
                if (heights[i] < heights[j]) {
                    result = heights[i] * (j - i) * 2;
                }
                else {
                    result = heights[j] * (j - i) * 2;
                }
            }
            else {
                if (heights[i] < heights[j]) {
                    result += heights[i] * 2 * 2;
                }
                else {
                    result += heights[j] * 2 * 2;
                }
            }
            left = heights[i];
            right = heights[j];
        }
    }

    cout << result << endl;
    return 0;
}