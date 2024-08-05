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

// solution 1: iterative
// class Solution {
// public:
//   vector<int> inorderTraversal(TreeNode *root) {
//     if (!root)
//       return {};

//     vector<int> ans;
//     stack<TreeNode *> st;
//     st.push(root);
//     root = root->left;
//     while (!st.empty()) {
//       while (root) {
//         st.push(root);
//         root = root->left;
//       }
//       root = st.top();
//       st.pop();
//       ans.push_back(root->val);
//       root = root->right;
//       while (root) {
//         st.push(root);
//         root = root->left;
//       }
//     }
//     return ans;
//   }
// };

// solution 2 : MORRIS INORDER
class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    if (!root)
      return {};

    vector<int> ans;
    TreeNode *curr = root;

    while (curr) {
      if (curr->left == NULL) {
        ans.push_back(curr->val);
        curr = curr->right;
      } else {
        TreeNode *prev = curr->left;

        while (prev->right && prev->right != curr)
          prev = prev->right;

        // create thread
        if (prev->right == NULL) {
          prev->right = curr;
          curr = curr->left;
        } else {
          prev->right = NULL;
          ans.push_back(curr->val);
          curr = curr->right;
        }
      }
    }
    return ans;
  }
};