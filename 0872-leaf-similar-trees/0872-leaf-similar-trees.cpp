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
    bool isLeaf(TreeNode *root) {
        return !root->left && !root->right;
    }
    
    void getLeafSequence(TreeNode *root, vector<int> &v){
        if (root != NULL)
        {
            getLeafSequence(root->left,v);
            if (isLeaf(root))
                v.push_back(root->val);
            getLeafSequence(root->right,v);
        }
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2){
        vector<int> a, b;
        getLeafSequence(root1, a);
        getLeafSequence(root2, b);

        return a == b;
    }
};