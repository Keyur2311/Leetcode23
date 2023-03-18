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
    int idx = 0,ans=0;
    bool found = false;
    void inorder(TreeNode* root,int k){
        if(root && !found){
            inorder(root->left,k);
            idx++;
            if(idx==k){
                ans=root->val;
                found = true;
                return;
            }
            inorder(root->right,k);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return ans;
    }
};