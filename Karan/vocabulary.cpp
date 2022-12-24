#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TrieNode {
  TrieNode* parent;
  TrieNode* children[26];
  size_t childrenCount;
  bool endOfWord;
  char payload;

  TrieNode(char aPayload, bool aEndOfWord, TrieNode* aParent) {
    for (size_t i = 0; i < 26; i++) children[i] = nullptr;
    childrenCount = 0;
    payload = aPayload;
    endOfWord = aEndOfWord;
    parent = aParent;
  }

  void insert(string s, size_t index = 0) {
    if (index == s.length()) endOfWord = true;
    else {
      if (children[s[index] - 'A'] == nullptr) {
        children[s[index] - 'A'] = new TrieNode(s[index], false, this);
        childrenCount++;
      }
      children[s[index] - 'A']->insert(s, index+1);
    }
  }
};
TrieNode* root = new TrieNode('*', false, nullptr);

void removeFromTrie(string s) {
  TrieNode* current = root;
  for (const char& c : s) {
    if (current->children[c - 'A'] == nullptr) return; // String not found in trie
    current = current->children[c - 'A'];
  }
  current->endOfWord = false;
  while (!current->endOfWord && current->childrenCount == 0) {
    char ch = current->payload;
    current = current->parent;
    if (current == nullptr) break; // Entire Trie Removed
    current->children[ch - 'A'] = nullptr;
    current->childrenCount--;
  }
}

vector<string> alice, bob;

void makeTrie() {
  for (const string& s : bob) root->insert(s);
}

// Delineates Entire Trie For Testing Purposes
void testTrie(TrieNode* current, string s) {
  if (current != root) s += current->payload;
  cout << "Current: " << s << " | EOW? " << current->endOfWord << endl;
  for (size_t i = 0; i < 26; i++)
    if (current->children[i] != nullptr)
      testTrie(current->children[i], s);
}

bool findAndRemoveLeastMatchingString(string prefix, string rest) {
  TrieNode* current = root;
  string s = prefix;

  // Match Prefix As Required
  for (const char& c : prefix) {
    if (current->children[c - 'A'] == nullptr) return false; // Prefix not found in trie
    current = current->children[c - 'A'];
  }

  // Avoid Matching Suffix As Far As Possible
  for (size_t restIndex = 0; restIndex < rest.size(); restIndex++) {
    // If End Of Word Reached, Remove From Trie
    if (current->endOfWord) {
      removeFromTrie(s);
      return true;
    }
    // Else, Find Least Matching Branch, Then Continue
    size_t childIndex;
    for (size_t i = 0; i < 26; i++) {
      if (current->children[i] != nullptr) {
        childIndex = i;
        if (i + 'A' != rest[restIndex]) break;
      }
    }
    current = current->children[childIndex];
    s += current->payload;
  }

  // If Suffix Exhausted But End Of Word Not Reached, Pick Any Random Branch
  while (!current->endOfWord) {
    for (size_t i = 0; i < 26; i++) {
      if (current->children[i] != nullptr) {
        current = current->children[i];
        s += current->payload;
      }
    }
  }

  // Remove Bob's String From Trie & Return Match Found
  removeFromTrie(s);
  return true;
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
    for (size_t i = 1; i <= s.length(); i++) {
      string prefix = s.substr(0, i), suffix = s.substr(i);
      if (!findAndRemoveLeastMatchingString(prefix, suffix)) break;
      else res++;
    }
  }
  cout << "Result: " << res << endl;

  return 0;
}
