#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *createTree(vector<int> input);
vector<vector<int>> levelOrder(TreeNode *root);

int main(int argc, char const *argv[]) {
  vector<int> input1 = {3, 9, 20, NULL, NULL, 15, 7};
  vector<int> input2 = {1};
  vector<int> input3 = {1, 7, 9, 2, 6, NULL, 9, NULL, NULL, 5, 11, 5, NULL};

  TreeNode *tree_root1 = createTree(input1);
  // TreeNode *tree_root2 = createTree(input2);
  // TreeNode *tree_root3 = createTree(input3);

  levelOrder(tree_root1);
  return 0;
}

vector<vector<int>> levelOrder(TreeNode *root) {
  queue<TreeNode *> nodes;
  TreeNode *node;
  vector<vector<int>> lo;
  int count = 0, maxNodes = 1, loopCounter = 0, height = 0;

  if (root == nullptr)
    return {};

  if ((root->left == nullptr) && (root->right == nullptr)) {
    lo.push_back(vector<int>(1, root->val));
    return lo;
  }

  nodes.push(root);
  while (!nodes.empty()) {
    // pop the front of the queue
    // push the left and right of the popped node

    maxNodes = pow(2, height);

    node = nodes.front();
    nodes.pop();

    count++;
    cout << "popped: " << node->val << " count: " << count << endl;

    if (node->left != nullptr) {
      nodes.push(node->left);
    } else {
      count++;
    }

    if (node->right != nullptr) {
      nodes.push(node->right);
    } else {
      count++;
    }

    loopCounter++;
  }

  return lo;
}

// create a tree given a vector of input elements
// returns root of tree
TreeNode *createTree(vector<int> input) {
  queue<TreeNode *> nodes;
  TreeNode *node, *parent, *root;

  if (input.size() == 0) {
    return nullptr;
  }

  // First element of input vector will always be the root node
  root = new TreeNode(input[0]);

  if (input.size() == 1) {
    return root;
  }

  parent = root;
  bool isLeftFilled = false;

  for (int i = 1; i < input.size(); i++) {
    // cout << input[i] << ": ";
    if (input[i] != NULL) {
      node = new TreeNode(input[i]);
      // add node to queue
      nodes.push(node);
      if (!isLeftFilled) {
        parent->left = node;
        // cout << "adding " << node->val << " to left of " << parent->val << endl;
        isLeftFilled = true;
      } else {
        parent->right = node;
        // cout << "adding " << node->val << " to right of " << parent->val << endl;
        parent = nodes.front();
        // cout << "new parent: " << parent->val << endl;
        nodes.pop();
        isLeftFilled = false;
      }
      // cout << "adding " << node->val << " to " << parent->val << endl;
    } else {
      if (!isLeftFilled) {
        parent->left = nullptr;
        isLeftFilled = true;
        // cout << "adding null to left of " << parent->val << endl;
      } else {
        parent->right = nullptr;
        // cout << "adding null to right of " << parent->val << endl;
        parent = nodes.front();
        // cout << "new parent: " << parent->val << endl;
        nodes.pop();
        isLeftFilled = false;
      }
    }
  }

  return root;
}