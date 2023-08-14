#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    multiset<string> noisy;
    map<int, string> rooms;
    map<string, int> roomsFlipped;
    for (int i = 0; i < 20; i++) {
        int r;
        string n;
        cin >> r >> n;
        rooms[r] = n;
        roomsFlipped[n] = r;
    }
    for (int i = 0; i < 5; i++) {
        char f, t;
        int s, j = 101;
        cin >> f >> s >> t;
        if (f == 'O') j = 102;
        for (; j <= 120; j += 2)
            if (j % s && rooms[j][0] != t)
                noisy.insert(rooms[j]);
    }
    set<int> mostNoisy;
    int max = 0;
    for (const string& name : noisy) {
        if (noisy.count(name) > max) {
            max = noisy.count(name);
            mostNoisy.clear();
        }
        if (noisy.count(name) == max) mostNoisy.insert(roomsFlipped[name]);
    }
    for (const int& room : mostNoisy)
        cout << rooms[room] << endl;
    return 0;
}
