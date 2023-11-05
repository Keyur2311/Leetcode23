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
  int findMax(TreeNode *root) {
    if (root == NULL)
      return 0;

    int l = findMax(root->left);
    int r = findMax(root->right);

    return max(l, r) + 1;
  }

  void countNodes(TreeNode *root, int h, int &sum, int &height) {
    if (root == NULL)
      return;

    if (h == height)
      sum += root->val;

    countNodes(root->left, h + 1, sum, height);
    countNodes(root->right, h + 1, sum, height);
  }

  int deepestLeavesSum(TreeNode *root) {

    int height = findMax(root);

    int sum = 0, h = 1;
    countNodes(root, h, sum, height);

    return sum;
  }
};