#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Coord {
    int x, y, n;

    Coord(int aX, int aY) {
        x = aX;
        y = aY;
        n = -1;
    }

    double dist(Coord& aOther) {
        return sqrt(pow(aOther.x - x, 2) + pow(aOther.y - y, 2));
    }
};

void check(vector<Coord>& coords, uint i) {
    uint n = coords.size();

    for (int j = 0; j < n; j++) {
        if (j != i) {
            // cos(C) = (a2 + b2 - c2) / 2ab
            double x_to_y = coords[i].dist(coords[j]);
            double y_to_z = coords[j].dist(coords[n - 1]);
            double x_to_z = coords[i].dist(coords[n - 1]);
            double angle = acos((pow(x_to_y, 2) + pow(y_to_z, 2) - pow(x_to_z, 2)) / (2 * x_to_y * y_to_z)) * 180 / M_PI;

            if (angle >= (90.0 - 1e-6)) {
                if (coords[j].n == -1) {
                    check(coords, j);
                }
                coords[i].n = max(coords[i].n, coords[j].n + 1);
            }
        }
    }
    coords[i].n = max(coords[i].n, 0);
}

int main() {
    uint n;
    cin >> n;

    vector<Coord> coords;
    for (uint i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        coords.push_back(Coord(x, y));
    }
    coords[n - 1].n = 0;

    check(coords, 0);

    cout << coords[0].n << endl;
    return 0;
}
