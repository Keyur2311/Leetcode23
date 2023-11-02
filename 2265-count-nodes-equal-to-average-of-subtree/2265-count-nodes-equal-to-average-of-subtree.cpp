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
  int calculateSum(TreeNode *root) {
    if (!root)
      return 0;

    int sum = root->val;
    sum += calculateSum(root->left);
    sum += calculateSum(root->right);

    return sum;
  }

  int calculateChild(TreeNode *root) {
    if (!root)
      return 0;

    int tot = 1;
    tot += calculateChild(root->left);
    tot += calculateChild(root->right);

    return tot;
  }

  void calculateTotalNodes(TreeNode *root, int &ans) {
    if (root == NULL)
      return;
    calculateTotalNodes(root->left, ans);

    int data = root->val;
    int sum = root->val, nodes = 1;
    if (root->left) {
      sum += calculateSum(root->left);
      nodes += calculateChild(root->left);
    }

    if (root->right) {
      sum += calculateSum(root->right);
      nodes += calculateChild(root->right);
    }

    int avg = sum / nodes;
    if (data == avg)
      ans += 1;

    calculateTotalNodes(root->right, ans);
  }
    
  int averageOfSubtree(TreeNode *root) {
    int ans = 0;
    calculateTotalNodes(root, ans);
    return ans;
  }
};