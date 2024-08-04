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
  TreeNode *buildBST(vector<int> &preorder, int l, int r) {
    if (l > r)
      return NULL;

    TreeNode *root = new TreeNode(preorder[l]);
    int idx = l;
    while (idx<(preorder.size()) && preorder[idx] <= root->val)
      idx++;

    root->left = buildBST(preorder, l + 1, idx - 1);
    root->right = buildBST(preorder, idx, r);

    return root;
  }
  TreeNode *bstFromPreorder(vector<int> &preorder) {

    int n = (int)preorder.size();
    return buildBST(preorder, 0, n - 1);
  }
};