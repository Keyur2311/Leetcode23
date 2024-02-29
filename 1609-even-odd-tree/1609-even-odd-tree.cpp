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
  bool isEvenOddTree(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    int parity = 1;

    while (!q.empty()) {
      int sz = (int)q.size();
      vector<int> temp;
      while (sz--) {
        auto fr = q.front();
        q.pop();

        temp.push_back(fr->val);

        if (fr->left)
          q.push(fr->left);
        if (fr->right)
          q.push(fr->right);
      }

      int n = (int)temp.size();

      if (parity & 1) {
        for (auto it : temp) {
          if (it % 2 == 0)
            return false;
        }

        for (int i = 1; i < n; i++) {
          if (temp[i - 1] < temp[i])
            continue;
          else
            return false;
        }

      } else {
        for (auto it : temp) {
          if (it % 2 != 0)
            return false;
        }

        for (int i = 0; i < n - 1; i++) {
          if (temp[i] > temp[i + 1])
            continue;
          else
            return false;
        }
      }
      if (parity == 1)
        parity = 0;
      else
        parity = 1;
    }
    return true;
  }
};