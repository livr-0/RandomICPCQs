#include <iostream>
#include <map>

using namespace std;

map<size_t, size_t> timeBlocks;
size_t n, h, v, w;

bool getTimeBlocks() {
    while (n-- > 0) {
        size_t x, y, startPos, endPos;
        cin >> x >> y;
        startPos = y + x * v;
        endPos = y + (x + w) * v;
        if (endPos - startPos >= h) {
            cout << "GAME OVER" << endl;
            return false;
        }
        startPos %= h;
        endPos %= h;
        if (endPos > startPos) {
            if (timeBlocks[startPos] < endPos) {
                timeBlocks[startPos] = endPos;
            }
        }
        else {
            timeBlocks[startPos] = h - 1;
            if (timeBlocks[0] < endPos) {
                timeBlocks[0] = endPos;
            }
        }
    }
    return true;
}

void amalgamateTimeBlocks() {
    bool firstIteration = true;
    size_t lastCloseValue;
    for (const pair<size_t, size_t>& block : timeBlocks) {
        if (firstIteration) {
            if (block.first != 0) {
                cout << "VICTORY" << endl;
                return;
            }
            firstIteration = false;
            lastCloseValue = block.second;
        }
        else {
            if (block.first > lastCloseValue + 1) {
                cout << "VICTORY" << endl;
                return;
            }
            if (block.second > lastCloseValue) lastCloseValue = block.second;
        }
    }
    cout << ((lastCloseValue == h - 1) ? "GAME OVER" : "VICTORY") << endl;
}

int main() {
    cin >> n >> h >> v >> w;
    if (getTimeBlocks()) {
        amalgamateTimeBlocks();
    }
    return 0;
}
