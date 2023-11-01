class Solution {
public:
  void findMax(TreeNode *root, int &curr, int &prev, int &mx) {
    if (root == NULL)
      return;

    findMax(root->left, curr, prev, mx);
    int data = root->val;
    if (data == prev)
      curr++;
    else
      curr = 1;

    mx = max(mx, curr);
    prev = data;
    findMax(root->right, curr, prev, mx);
  }

  void findModes(TreeNode *root, int &curr, int &prev, int &mx,
                 vector<int> &ans) {
    if (root == NULL)
      return;

    findModes(root->left, curr, prev, mx, ans);
    int data = root->val;
    if (data == prev)
      curr++;
    else
      curr = 1;

    if (curr == mx)
      ans.push_back(data);
    prev = data;

    findModes(root->right, curr, prev, mx, ans);
  }
  vector<int> findMode(TreeNode *root) {

    int curr = 1, prev = -1, mx = 1;
    findMax(root, curr, prev, mx);

    vector<int> ans;
    curr = 1, prev = -1;
    findModes(root, curr, prev, mx, ans);

    return ans;
  }
};