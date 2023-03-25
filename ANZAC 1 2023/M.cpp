#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int theirScore, matches = 0;
    string myStuff, theirStuff;
    cin >> theirScore >> myStuff >> theirStuff;

    for (size_t i = 0; i < myStuff.length(); i++)
        if (myStuff[i] == theirStuff[i])
            matches++;

    cout << myStuff.length() - abs(matches - theirScore) << endl;
    return 0;
}
