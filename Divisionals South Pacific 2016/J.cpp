#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<string> competitors;
string lastChar;

void initialiseVariables() {
    size_t n;
    cin >> n;
    for (; n > 0; n--) competitors.push(to_string(n));
    lastChar = "c";
}

void printAndPopTwo() {
    cout << competitors.top() << " ";
    competitors.pop();
    cout << competitors.top() << " ";
    competitors.pop();
}

void joust() {
    if (competitors.size() == 2) {
        printAndPopTwo();
        cout << "a" << endl;
    } else {
        printAndPopTwo();
        if (lastChar == "b") {
            cout << "c" << endl;
            lastChar = "c";
        } else {
            cout << "b" << endl;
            lastChar = "b";
        }
        competitors.push(lastChar);
    }
}

int main() {
    initialiseVariables();
    while (!competitors.empty()) joust();
    return 0;
}
