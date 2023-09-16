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
  TreeNode *solve(TreeNode *root1, TreeNode *root2) {

    TreeNode *newRoot = NULL;
    if (root1 != NULL && root2 != NULL)
      newRoot = new TreeNode(root1->val + root2->val);
    else if (root1 != NULL)
      newRoot = new TreeNode(root1->val);
    else if (root2 != NULL) {
      newRoot = new TreeNode(root2->val);
    }
    
    if(newRoot!=NULL){
    if (root1 != NULL && root2 != NULL) {
      newRoot->left = solve(root1->left, root2->left);
      newRoot->right = solve(root1->right, root2->right);
    } else if (root2 != NULL) {
      newRoot->left = solve(root1, root2->left);
      newRoot->right = solve(root1, root2->right);
    } else if (root1 != NULL) {
      newRoot->left = solve(root1->left, root2);
      newRoot->right = solve(root1->right, root2);
    } else {
      newRoot->left = NULL;
      newRoot->right = NULL;
    }
    }
    return newRoot;
  }
  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    if (root1 == NULL)
      return root2;
    else if (root2 == NULL)
      return root1;

    return solve(root1, root2);
  }
};