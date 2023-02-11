#include <iostream>
#include <unordered_set>

using namespace std;

struct TreeNode {
  TreeNode* left;
  TreeNode* right;
  size_t payload;
  TreeNode(size_t aPayload) : payload(aPayload), left(nullptr), right(nullptr) {}
  void insert(TreeNode* newTreeNode) {
    if (newTreeNode->payload >= this->payload) {
      if (right == nullptr) right = newTreeNode;
      else right->insert(newTreeNode);
    } else {
      if (left == nullptr) left = newTreeNode;
      else left->insert(newTreeNode);
    }
  }
  string traverse() {
    if (left == nullptr && right == nullptr) return "|";
    string s = "";
    if (left != nullptr) s += "l" + left->traverse() + ".";
    if (right != nullptr) s += "r" + right->traverse() + ".";
    return s;
  }
};

int main() {
  size_t a, b;
  cin >> a >> b;
  unordered_set<string> stuff;

  while (a-- > 0) {
    TreeNode* root = nullptr;
    for (size_t i = 0; i < b; i++) {
      size_t payload; cin >> payload;
      TreeNode* newT = new TreeNode(payload);
      if (root == nullptr) root = newT;
      else root->insert(newT);
    }
    stuff.insert(root->traverse());
  }

  cout << stuff.size() << endl;
  return 0;
}
