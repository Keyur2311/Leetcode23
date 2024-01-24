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
  bool isleaf(TreeNode *node) {
    return (bool)(node && !node->left && !node->right);
  }

  void solve(TreeNode *root, int &ans, int &odd, int &even,
             unordered_map<int, int> &mp) {
    if (!root)
      return;

    mp[root->val]++;
    int fr = mp[root->val];

    if (fr & 1)
      odd++, even--;
    else
      even++, odd--;

    if (isleaf(root)) {
      if (odd <= 1)
        ans++;
    }

    solve(root->left, ans, odd, even, mp);
    solve(root->right, ans, odd, even, mp);

    mp[root->val]--;
    if (fr & 1)
      odd--, even++;
    else
      even--, odd++;
  }

  int pseudoPalindromicPaths(TreeNode *root) {
    int ans = 0, odd = 0, even = 0;
    unordered_map<int, int> mp;
    solve(root, ans, odd, even, mp);
    return ans;
  }
};