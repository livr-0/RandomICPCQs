#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long g;
vector<vector<long long>> grid(10001, vector<long long>(10001, 0));

long long getDistance(long long x1, long long y1, long long x2, long long y2) {
    return ceil(sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}

void clearCell(long long xCoord, long long yCoord) {
    if (xCoord >= 0 && yCoord >= 0 && xCoord <= 10000 && yCoord <= 10000) {
        g -= grid[xCoord][yCoord];
        grid[xCoord][yCoord] = 0;
    }
}

void clearArea(long long x, long long y, long long r) {
    for (long long i = r; i >= 0; i--) {
        for (long long j = 0; getDistance(x - i, y - j, x, y) <= r; j++) {
            long long xCoord = x - i, yCoord = y - j;
            clearCell(xCoord, yCoord);
            yCoord = y + j;
            clearCell(xCoord, yCoord);
            xCoord = x + i;
            clearCell(xCoord, yCoord);
            yCoord = y - j;
            clearCell(xCoord, yCoord);
        }
    }
}

int main() {
    cin >> g;
    for (long long i = 0; i < g; i++) {
        long long x, y;
        cin >> x >> y;
        grid[x][y]++;
    }
    long long m;
    cin >> m;
    while (m--) {
        long long x, y, r;
        cin >> x >> y >> r;
        clearArea(x, y, r);
    }
    cout << g << endl;
    return 0;
}
