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
  bool evaluateTree(TreeNode *root) {
    if (root->left == NULL && root->right == NULL)
      return (bool)(root->val);

    bool l = evaluateTree(root->left);
    bool r = evaluateTree(root->right);

    bool ans = false;
    if (root->val == 2)
      ans = l || r;
    else
      ans = l && r;

    return ans;
  }
};