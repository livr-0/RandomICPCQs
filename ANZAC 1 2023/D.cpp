#include <iostream>
#include <unordered_set>
#include <queue>
#include <tuple>

using namespace std;

unordered_set<string> visited;
queue<pair<size_t, string>> frontier; // { pathLength, node }

void rotateChar(char& c) {
    (c != 'F') ? ++c : c = 'A';
}

string clickOn(string s, size_t i) {
    switch (s[i]) {
    case 'A':
        if (i != 0) rotateChar(s[i - 1]);
        if (i != 7) rotateChar(s[i + 1]);
        break;
    case 'B':
        if (i != 7 && i != 0) s[i + 1] = s[i - 1];
        break;
    case 'C':
        rotateChar(s[7 - i]);
        break;
    case 'D':
        if (i <= 3) for (int j = i - 1; j >= 0; j--) rotateChar(s[j]);
        else for (int j = i + 1; j <= 7; j++) rotateChar(s[j]);
        break;
    case 'E':
        if (i != 0 && i != 7) {
            if (i <= 3) {
                rotateChar(s[0]);
                rotateChar(s[i * 2]);
            } else {
                rotateChar(s[7]);
                rotateChar(s[i * 2 - 7]);
            }
        }
        break;
    case 'F':
        ((i + 1) % 2 == 0) ? rotateChar(s[((i + 1) / 2) - 1]) : rotateChar(s[(((i + 1) + 9) / 2) - 1]);
        break;
    default: break;
    }
    return s;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    frontier.push({ 0, s1 });

    while (!frontier.empty()) {
        size_t pathLength = frontier.front().first;
        string node = frontier.front().second;
        frontier.pop();
        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            if (node == s2) {
                cout << pathLength << endl;
                return 0;
            }
            for (size_t i = 0; i < 8; i++) {
                string child = clickOn(node, i);
                if (visited.find(child) == visited.end()) frontier.push({ pathLength + 1, child });
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
