#include <iostream>
#include <unordered_map>
#include <tuple>
#include <queue>

using namespace std;

typedef tuple<size_t, string, string> stringNode; // { distance, node, parent }

struct Compare { bool operator()(stringNode& a, stringNode& b) { return get<0>(a) > get<0>(b); } };

unordered_map<string, string> visited;
priority_queue<stringNode, vector<stringNode>, Compare> frontier;
string s2;

void rotateChar(char& c) {
    (c != 'F') ? ++c : c = 'A';
}

size_t backtrack(string node) {
    return (visited[node] == node)? (0) : (1 + backtrack(visited[node]));
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
    string s1;
    cin >> s1 >> s2;

    frontier.push({ 0, s1, s1 });

    while (!frontier.empty()) {
        stringNode fr = frontier.top();
        frontier.pop();
        string node = get<1>(fr);
        if (visited[node] == "") {
            visited[node] = get<2>(fr);
            if (node == s2) {
                cout << backtrack(node) << endl;
                return 0;
            }
            for (size_t i = 0; i < 8; i++) {
                string child = clickOn(node, i);
                if (visited[child] == "") frontier.push({ 1 + get<0>(fr), child, node });
            }
        }
    }

    cout << "-1" << endl;
    return 0;
}
