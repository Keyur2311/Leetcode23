/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  vector<TreeNode *> buildBST(int l, int r) {
    if (l > r) {
      vector<TreeNode *> base(1, NULL);
      return base;
    }

    if (l == r) {
      vector<TreeNode *> base;
      TreeNode *temp = new TreeNode(l);
      base.push_back(temp);
      return base;
    }

    vector<TreeNode *> v;
    for (int i = l; i <= r; i++) {
      
      TreeNode *node = new TreeNode(i);
      vector<TreeNode *> left = buildBST(l, i - 1);
      vector<TreeNode *> right = buildBST(i + 1, r);

      for (auto lnode : left) {
        for (auto rnode : right) {
          TreeNode *root = new TreeNode(i);
          root->left = lnode;
          root->right = rnode;
          v.push_back(root);
        }
      }
    }

    return v;
  }
  vector<TreeNode *> generateTrees(int n) {

    vector<TreeNode *> ans = buildBST(1, n);
    return ans;
  }
};