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
    int prev = -1;
    void getAns(TreeNode *root, int &ans)
    {
        if (root != NULL)
        {
            getAns(root->left,ans);
            if(prev!=-1) ans=min(ans,abs(prev - root->val));
            prev = root->val;
            getAns(root->right,ans);
        }
    }
    int getMinimumDifference(TreeNode *root)
    {
        int ans = INT_MAX;
        getAns(root, ans);
        return ans;
    }
};