#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

int main() {
    deque<double> values;
    for (int i = 1; i <= 100; i++) values.push_back(i);
    size_t n, res = 0;
    cin >> n;
    while (n-- > 0) {
        string s;
        int k;
        cin >> s >> k;
        if (s[0] == 'A') for (int i = 0; i < values.size(); i++) values[i] += k;
        else if (s[0] == 'M') for (int i = 0; i < values.size(); i++) values[i] *= k;
        else if (s[0] == 'S') {
            for (int i = 0; i < values.size(); i++) values[i] -= k;
            while (values.front() < 0) {
                res++;
                values.pop_front();
            }
        }
        else {
            for (int i = 0; i < values.size(); i++) values[i] /= k;
            deque<double> temp;
            for (size_t i = 0 ; i < values.size(); i++)
                if (floor(values[i]) == ceil(values[i])) temp.push_back(values[i]);
                else res++;
            values = temp;
        }
    }
    cout << res << endl;
    return 0;
}
