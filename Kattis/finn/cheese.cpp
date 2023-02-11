#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

const double PI = acos(-1.0);

double clamp(double x, double low, double high) {
    return max(low, min(high, x));
}

struct Hole {
    double r, x, y, z;

    double volume(double start, double end) const {
        start -= z;
        end -= z;
        start = clamp(start, -r, r);
        end = clamp(end, -r, r);
        return PI * (pow(r, 2) * (end - start) + (pow(start, 3) - pow(end, 3)) / 3);
    }
};

double calcVolume(const std::vector<Hole> &holes, double start, double end) {
    double volume = 100.0 * 100.0 * (end - start);

    for (const Hole &hole : holes) {
        volume -= hole.volume(start, end);
    }

    return volume;
}

int main() {
    cout << setprecision(16);

    int holeCount, sliceCount;
    cin >> holeCount >> sliceCount;

    std::vector<Hole> holes(holeCount);

    for (int i = 0; i < holeCount; i++) {
        int r, x, y, z;
        cin >> r >> x >> y >> z;

        Hole &h = holes[i];
        h.r = r / 1000.0;
        h.x = x / 1000.0;
        h.y = y / 1000.0;
        h.z = z / 1000.0;
    }

    double totalVol = calcVolume(holes, 0.0, 100.0);
    double targetVol = totalVol / sliceCount;

    //cout << "Total Volume: " << totalVol << endl;
    //cout << "Slice Volume: " << targetVol << endl;

    double lastSlice = 0.0;
    for (int i = 0; i < sliceCount - 1; i++) {
        double lowerBound = lastSlice, upperBound = 100.0;
        while (true) {
            double guess = (lowerBound + upperBound) / 2;
            double sliceVol = calcVolume(holes, lastSlice, guess);
            if (sliceVol > targetVol) {
                upperBound = guess;
            } else {
                lowerBound = guess;
            }
            if (abs(upperBound - lowerBound) < 1e-7) {
                cout << guess - lastSlice << endl;
                lastSlice = guess;
                break;
            }
        }
    }
    cout << 100.0 - lastSlice << endl;
}
