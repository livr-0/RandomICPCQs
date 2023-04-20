#include <iostream>
#include <vector>

using namespace std;

// turn left 90 degrees
vector<vector<size_t>> tilt(vector<vector<size_t>> grid) {
    vector<vector<size_t>> res;
    for (int j = 3; j >= 0; j--) {
        vector<size_t> row;
        for (int i = 0; i <= 3; i++) row.push_back(grid[i][j]);
        res.push_back(row);
    }
    return res;
}

// rotate 180 degrees
vector<vector<size_t>> flip(vector<vector<size_t>> grid) {
    return tilt(tilt(grid));
}

// turn right 90 degrees
vector<vector<size_t>> untilt(vector<vector<size_t>> grid) {
    return flip(tilt(grid));
}

int main() {
    vector<vector<size_t>> grid(4, vector<size_t>(4, 0)), res(4, vector<size_t>(4, 0));
    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++) {
            size_t v;
            cin >> v;
            grid[i][j] = v;
        }

    // tilt &/or flip graphs so that only swipe left is implemented
    bool flipped = 0, tilted = 0;
    size_t dir;
    cin >> dir;
    if (dir == 3) { dir = 1; grid = flip(grid); flipped = 1; }
    if (dir == 1) { grid = tilt(grid); dir = 0; tilted = 1; }
    if (dir == 2) { grid = flip(grid); dir = 0; flipped = 1; }

    // swipe left operation
    for (size_t i = 0; i < 4; i++) {
        vector<size_t> nums, fNums;
        // get rid of the 0s
        for (size_t j = 0; j < 4; j++) if (grid[i][j]) nums.push_back(grid[i][j]);
        // merge compatible neighbours
        for (int j = 0; j < nums.size(); j++) {
            if (j == nums.size() - 1) {
                fNums.push_back(nums[j]);
                break;
            }
            if (nums[j] == nums[j + 1]) {
                fNums.push_back(nums[j] * 2);
                j++;
            }
            else fNums.push_back(nums[j]);
        }
        // prepare resultant grid
        for (size_t j = 0; j < fNums.size(); j++) res[i][j] = fNums[j];
    }

    // if graphs have been tilted &/or flipped, undo the transformation
    if (flipped) res = flip(res);
    if (tilted) res = untilt(res);
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 4; j++) cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}
