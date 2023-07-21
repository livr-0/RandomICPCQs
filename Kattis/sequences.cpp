#include <iostream>

using namespace std;
const size_t mod = 1000000007;

int main() {
    string in;
    cin >> in;
    size_t branches = 1, ones = 0, swaps = 0;

    for (char c : in) {
        if (c == '0') {
            swaps = (swaps + ones) % mod;
            ones = ones;
            branches = branches;
        }
        else if (c == '1') {
            ones = (ones + branches) % mod;
            swaps = swaps;
            branches = branches;
        }
        else {
            swaps = ((swaps + ones) + swaps) % mod;
            ones = (ones + (ones + branches)) % mod;
            branches = branches * 2 % mod;
        }
    }

    cout << swaps << endl;
    return 0;
}