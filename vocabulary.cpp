#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// Trie ADT
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

// Finds A String With Specified Prefix In The Trie (Returns Blank String If None Found)
string findStringInTrieWithPrefix(string prefix) {
  TrieNode* current = root;
  for (const char& c : prefix) {
    if (current->nodes[c - 'A'] != nullptr) current = current->nodes[c - 'A'];
    else return "";
  }
  while (!current->wordEnd) {
    TrieNode* temp = current;
    for (size_t i = 0; i < 26; i++) {
      if  (current->nodes[i] != nullptr) {
        prefix += i + 'A';
        current = current->nodes[i];
        break;
      }
    }
    if (temp == current) return "";
  }
  return prefix;
}

// Remove a specific key from the trie
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

// Prints Out The Entire Trie For Testing
void testTrie(TrieNode* node, string current) {
  cout << "Current: " << current << " | End Of Word?: " << node->wordEnd << endl;
  for (size_t i = 0; i < 26; i++) {
    if (node->nodes[i] != nullptr) {
      char c = i + 'A';
      string s(1, c);
      testTrie(node->nodes[i], current + s);
    }
  }
}

void makeTrie(const vector<string>& v) {
  for (const string& s : v) root->insert(s);
}

int main() {
  vector<string> alice, bob;

  // Get Input
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
    makeTrie(bob); // Trie is created everytime as elements are removed during execution
    cout << "For: " << s << endl;
    size_t tempRes = 0;
    bool notFound = false;
    for (int j = s.length(); j > 0; j--) {
      notFound = false;
      cout << "At: " << s.substr(0, j) <<  endl;
      string r = findStringInTrieWithPrefix(s.substr(0, j));
      if (r != "") {
        cout << "Found (" << r << ")" << endl;
        removeFromTrie(r);
        tempRes++;
      }
      else {
        cout << "Not found" << endl;
        notFound = true;
        if (j != s.length()) j += 2;
        tempRes = 0;
        for (const string& b : bob) root->insert(b);
      }
    }
    res += tempRes;
  }
  cout << "Result: " << res << endl;
  return 0;
}
