#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int x, y, x1, y1, x2, y2, xf, yf;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;

         if (x <= x1 && y <= y1) xf = x1, yf = y1;
    else if (x >= x2 && y <= y1) xf = x2, yf = y1;
    else if (x <= x1 && y >= y2) xf = x1, yf = y2;
    else if (x >= x2 && y >= y2) xf = x2, yf = y2;
    else if (x <= x1) xf = x1, yf = y;
    else if (x >= x2) xf = x2, yf = y;
    else if (y <= y1) xf = x, yf = y1;
    else if (y >= y2) xf = x, yf = y2;

    int dx = x - xf, dy = y - yf;
    cout.precision(3);
    cout << fixed;
    cout << sqrt(dx * dx + dy * dy) << endl;

    return 0;
}
