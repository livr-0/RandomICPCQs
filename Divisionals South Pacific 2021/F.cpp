#include <iostream>
#include <cmath>
#include <set>

using namespace std;

const double eps = 1e-8;

set<pair<int, int>> pointsContained;
double x, y, w, h, r, sx, sy, ex, ey;

double getDistance(int x1, int x2, int y1, int y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

void checkCircleContainment(int X, int Y) {
    if (getDistance(X, x, Y, y) - eps < r) pointsContained.insert({ x, y });
    if (getDistance(X, x + w, Y, y) - eps < r) pointsContained.insert({ x + w, y });
    if (getDistance(X, x, Y, y + h) - eps < r) pointsContained.insert({ x, y + h });
    if (getDistance(X, x + w, Y, y + h) - eps < r) pointsContained.insert({ x + w, y + h });
}

int main() {
    cin >> x >> y >> w >> h >> r >> sx >> sy >> ex >> ey;

    double s = (ey - sy) / (ex - sx); // slope of farmer's path
    double c = sy - (s * sx); // x-intercept of farmer's path
    double mx = x + w/2, my = y + h/2; // rectangle midpoint
    double ps = (-1.0)/s; // slope of perpendicular path
    double pc = my - (ps * mx); // x-intercept of perpendicular path
    // calculating farmer's closest point to rect center
    double px = (c - pc) / (ps - s);
    double py = (ps * px) + pc;

    checkCircleContainment(sx, sy);
    checkCircleContainment(ex, ey);
    if (ex != sx) {
        if ((px > sx && px < ex) || (px > ex && px < sx)) checkCircleContainment(px, py);
    } else {
        if ((py > sy && py < ey) || (py > ey && py < sy)) checkCircleContainment(px, py);
    }

    if (pointsContained.size() == 4) cout << "Oh no!" << endl;
    else cout << "Safe" << endl;
    return 0;
}
