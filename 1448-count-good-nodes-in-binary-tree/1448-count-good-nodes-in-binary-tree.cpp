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
    void countGoodNodes(TreeNode *root, int mx, int &count) {
        if (!root)
            return;

        if (root->val >= mx){
            count++;
            mx = root->val;
        }
        countGoodNodes(root->left, mx, count);
        countGoodNodes(root->right, mx, count);
    }
    
    int goodNodes(TreeNode *root){
        int count = 0, mx = root->val;
        countGoodNodes(root, mx, count);
        return count;
    }
};