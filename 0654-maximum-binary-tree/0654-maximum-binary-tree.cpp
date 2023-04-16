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
class Solution{
public:
    TreeNode *buildMaxTree(int l, int r, vector<int> nums){
        if (l > r)
            return NULL;

        int  mx_idx = l;
        for (int i = l; i <= r; i++){
            if (nums[i] > nums[mx_idx])
                mx_idx = i;
        }

        TreeNode *node = new TreeNode(nums[mx_idx]);

        node->left = buildMaxTree(l, mx_idx - 1, nums);
        node->right = buildMaxTree(mx_idx + 1, r, nums);

        return node;
    }

    TreeNode *constructMaximumBinaryTree(vector<int> &nums){
        int n = (int)nums.size();
        TreeNode *ans = buildMaxTree(0, n - 1, nums);
        return ans;
    }
};
