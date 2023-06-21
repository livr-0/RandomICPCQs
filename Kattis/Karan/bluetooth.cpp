#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, char> teeth;

void make_teeth() {
    for (int i = 1; i <= 8; i++) {
        teeth[to_string(i) + "+"] = 'f';
        teeth[to_string(i) + "-"] = 'f';
        teeth["+" + to_string(i)] = 'f';
        teeth["-" + to_string(i)] = 'f';
    }
}

void get_input() {
    int n;
    cin >> n;
    while (n--) {
        string a;
        char b;
        cin >> a >> b;
        teeth[a] = b;
    }
}

bool check_left() {
    bool has_upper = false, has_lower = false;
    for (int i = 1; i <= 8; i++) {
        if (teeth["+" + to_string(i)] == 'b' || teeth["-" + to_string(i)] == 'b')
            return false;
        if (teeth["+" + to_string(i)] == 'f') has_upper = true;
        if (teeth["-" + to_string(i)] == 'f') has_lower = true;
    }
    return has_upper && has_lower;
}

bool check_right() {
    bool has_upper = false, has_lower = false;
    for (int i = 1; i <= 8; i++) {
        if (teeth[to_string(i) + "+"] == 'b' || teeth[to_string(i) + "-"] == 'b')
            return false;
        if (teeth[to_string(i) + "+"] == 'f') has_upper = true;
        if (teeth[to_string(i) + "-"] == 'f') has_lower = true;
    }
    return has_upper && has_lower;
}

int main() {
    make_teeth();
    get_input();
    if (check_left()) cout << 0 << endl;
    else if (check_right()) cout << 1 << endl;
    else cout << 2 << endl;
    return 0;
}
