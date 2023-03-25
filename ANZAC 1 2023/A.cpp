#include <iostream>
#include <set>

using namespace std;

int main() {
    set <size_t> fibs = { 1, 2, 3, 5, 8 };
    int x;
    cin >> x;
    for (int i = 1; i <= x; i++) {
        cout << ((fibs.find(i) != fibs.end()) ? "fizz" : "buzz");
    }
}
