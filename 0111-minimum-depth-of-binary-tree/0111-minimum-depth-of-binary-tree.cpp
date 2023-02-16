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
    int minDepth(TreeNode* root) {
         if (root == NULL)
            return 0;
        else if (root->left == NULL && root->right == NULL)
            return 1;
        int l = INT32_MAX,r=INT32_MAX;
        if(root->left)
        l = minDepth(root->left);
        if(root->right)
        r = minDepth(root->right);
        return min(l,r)+1;
    }
};