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
    TreeNode* prev = NULL;
    bool checkBST(TreeNode* root){
       if(root){
           if(!checkBST(root->left)) return false;
           if(prev!=NULL && root->val <= prev->val) return false;
           prev = root;
           return checkBST(root->right);
       }
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
       return checkBST(root);
    }
};