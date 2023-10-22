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
   TreeNode *construct(vector<int> &arr, int lo, int hi) {
    if (lo > hi)
      return NULL;

    int mid = (lo + hi) / 2;
    TreeNode *node = new TreeNode(arr[mid]);
    node->left = construct(arr, lo, mid - 1);
    node->right = construct(arr, mid + 1, hi);

    return node;
  }
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    int n = (int)nums.size();
    TreeNode *node = construct(nums, 0, n - 1);
    return node;
  }
};