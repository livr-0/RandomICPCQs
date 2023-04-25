#include <iostream>

using namespace std;

int main() {
    string name;
    size_t age, weight;
    cin >> name >> age >> weight;
    cout << name << " ";
    if (age > 17 || weight >= 80) cout << "Senior" << endl;
    else cout << "Junior" << endl;
    cout << endl;
    return 0;
}
