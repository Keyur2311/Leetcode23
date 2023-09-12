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
  bool isLeaf(TreeNode *root) { return !root->left && !root->right; }

  void solve(TreeNode *root, int targetSum, vector<int> &curr,
             vector<vector<int>> &ans) {

    if (isLeaf(root)) {
      targetSum -= (root->val);
      curr.push_back(root->val);

      if (targetSum == 0)
        ans.push_back(curr);

      targetSum += (root->val);
      curr.pop_back();
      return;
    }

    int val = root->val;
    curr.push_back(root->val);

    if (root->left)
      solve(root->left, targetSum - val, curr, ans);
    if (root->right)
      solve(root->right, targetSum - val, curr, ans);

    curr.pop_back();
  }
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    if (root == NULL)
      return {};

    vector<vector<int>> ans;
    vector<int> curr;
    solve(root, targetSum, curr, ans);
    return ans;
  }
};