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
  bool isLeaf(TreeNode *curr) { return !curr->left && !curr->right; }
  
  int getMaxAns(TreeNode *curr, int &max_ans) {
    if (!curr)
      return 0;
    if (isLeaf(curr)) {
      max_ans = max(max_ans, curr->val);
      return curr->val;
    }
    int leftAns = getMaxAns(curr->left, max_ans);
    int rightAns = getMaxAns(curr->right, max_ans);
    max_ans = max(max_ans, max(curr->val,
                               max(leftAns, max(rightAns, leftAns + rightAns)) +
                                   curr->val));
    return max(curr->val, max(leftAns, rightAns) + curr->val);
  }

  int maxPathSum(TreeNode *root) {
    if (isLeaf(root))
      return root->val;
    int max_ans = INT_MIN;
    getMaxAns(root, max_ans);
    return max_ans;
  }
};