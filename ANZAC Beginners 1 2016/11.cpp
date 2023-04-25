#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    while (a + b + c != 0) {
        vector<double> v = { a, b, c };
        sort(v.begin(), v.end());
        if (v[2] < 125 || v[1] < 90 || v[2] < 0.25) cout << "not mailable" << endl;
        else if (v[2] <= 290 && v[1] <= 155 && v[0] <= 7) cout << "letter" << endl;
        else if (v[2] <= 380 && v[1] <= 300 && v[0] <= 50) cout << "packet" << endl;
        else if (v[2] + 2*v[1] + 2*v[0] <= 2100) cout << "parcel" << endl;
        else cout << "not mailable" << endl;
        cin >> a >> b >> c;
    }
    return 0;
}
