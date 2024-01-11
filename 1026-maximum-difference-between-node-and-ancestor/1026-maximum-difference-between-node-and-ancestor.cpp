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
  int ans = 0;

  int getmin(TreeNode *root) {

    if (!root)
      return 1e9;

    int l = getmin(root->left);
    int r = getmin(root->right);
    int val = root->val;

    if (l != 1e9)
      ans = max(ans, abs(l - val));

    if (r != 1e9)
      ans = max(ans, abs(r - val));

    return min({val, l, r});
  }

  int getmax(TreeNode *root) {

    if (!root)
      return -1;

    int l = getmax(root->left);
    int r = getmax(root->right);
    int val = root->val;

    if (l != -1)
      ans = max(ans, abs(l - val));
    if (r != -1)
      ans = max(ans, abs(r - val));

    return max({val, l, r});
  }
  int maxAncestorDiff(TreeNode *root) {
    getmin(root);
    getmax(root);
    return ans;
  }
};