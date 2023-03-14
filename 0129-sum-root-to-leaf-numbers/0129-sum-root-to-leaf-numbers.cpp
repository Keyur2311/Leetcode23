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
    int ans = 0;
    bool isLeaf(TreeNode * root){
        return !root->left && !root->right;
    }
    
    void getSum(TreeNode* root,string s){
        if(isLeaf(root)) {
            s+=to_string(root->val);
            ans += stoi(s);
            return;
        };
        s+=to_string(root->val);
        if(root->left)
        getSum(root->left,s);
        if(root->right)
        getSum(root->right,s);

    }
    
    int sumNumbers(TreeNode* root) {
        string s = "";
        getSum(root,s);
        return ans;
    }
};