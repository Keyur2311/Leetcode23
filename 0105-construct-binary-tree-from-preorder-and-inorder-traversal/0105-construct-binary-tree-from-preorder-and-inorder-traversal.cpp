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
  TreeNode *solve(vector<int> &in, int x, int y, vector<int> &pre, int a,
                  int b) {
    if (x > y || a > b)
      return NULL;
    TreeNode *root = new TreeNode(pre[a]);
    int idx = 0;
    while (pre[a] != in[idx])
      idx++;
    int cls = idx - x;
    root->left = solve(in, x, idx - 1, pre, a + 1, a + cls);
    root->right = solve(in, idx + 1, y, pre, a + cls + 1, b);
      
    return root;
  }
  TreeNode *buildTree(vector<int> &pre, vector<int> &in) {

    int n = (int)pre.size();
    return solve(in, 0, n - 1, pre, 0, n - 1);
  }
};