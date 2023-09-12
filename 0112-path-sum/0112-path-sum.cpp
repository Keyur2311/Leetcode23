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
  bool ok = false;
  bool isLeaf(TreeNode *root) { return !root->left && !root->right; }
  void pathsum(TreeNode *root, int sum, int targetSum) {

    if (isLeaf(root)) {
      sum += root->val;
      if (sum == targetSum) {
        ok = true;
        return;
      }
    }
    sum += root->val;
    if (root->left)
      pathsum(root->left, sum, targetSum);
    if (root->right)
      pathsum(root->right, sum, targetSum);
  }
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (root == NULL)
      return false;
    pathsum(root, 0, targetSum);
    return ok;
  }
};