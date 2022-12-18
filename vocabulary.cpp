#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TrieNode {
  TrieNode* parent;
  TrieNode* nodes[26];
  bool wordEnd;
  char payload;

  TrieNode(char aPayload, bool aWordEnd, TrieNode* aParent) {
    clearChildren();
    wordEnd = aWordEnd;
    payload = aPayload;
    parent = aParent;
  }

  void clearChildren() {
    for (size_t i = 0; i < 26; i++)
      nodes[i] = nullptr;
  }

  void insert(string s, size_t index = 0) {
    if (index == s.length()) wordEnd = true;
    else {
      if (nodes[s[index] - 'A'] == nullptr) nodes[s[index] - 'A'] = new TrieNode(s[index], false, this);
      nodes[s[index] - 'A']->insert(s, index + 1);
    }
  }

  size_t childrenCount() {
    size_t res = 0;
    for (size_t i = 0; i < 26; i++) if (nodes[i] != nullptr) res++;
    return res;
  }
};

TrieNode* root = new TrieNode('*', false, nullptr);
vector<string> alice, bob;

void removeFromTrie(string key) {
  TrieNode* current = root;
  for (const char& c : key) {
    if (current->nodes[c - 'A'] == nullptr) return; // Key not found in trie
    current = current->nodes[c - 'A'];
  }
  current->wordEnd = false;
  while (current != nullptr) {
    if (current->childrenCount() == 0) {
      char payload = current->payload;
      current = current->parent;
      current->nodes[payload - 'A'] = nullptr;
    }
    else break;
  }
}

void makeTrie() {
  for (const string& s : bob) root->insert(s);
}

string findLeastMatching(string s, char next) {
  string temp = "";
  TrieNode* current = root;
  for (const char& c : s) {
    if (current->nodes[c - 'A'] == nullptr) return "!";
    temp += s;
    current = current->nodes[c - 'A'];
  }
  if (current->wordEnd) return temp;
  size_t nextIndex;
  for (size_t i = 0; i < 26; i++) {
    if (current->nodes[i] != nullptr) {
      nextIndex = i;
      if ((i + 'A') != next) break;
    }
  }
  current = current->nodes[nextIndex];
  while (!current->wordEnd) {
    for (size_t i = 0; i < 26; i++) {
      if (current->nodes[i] != nullptr) {
        current = current->nodes[i];
        break;
      }
    }
  }
  return temp;
}

int main() {
  size_t a, b;
  cin >> a >> b;
  while (a-- > 0) {
    string s; cin >> s;
    alice.push_back(s);
  }
  while (b-- > 0) {
    string s; cin >> s;
    bob.push_back(s);
  }
  size_t res = 0;
  for (const string& s : alice) {
    makeTrie();
    for (size_t i = 1; i < s.length() - 1; i++) {
      string q = s.substr(0, i);
      string r = findLeastMatching(q, s[i+1]);
      if (r == "!") break;
      else {
        removeFromTrie(r);
        res++;
      }
    }
  }
  cout << "Result: " << res << endl;
  return 0;
}
