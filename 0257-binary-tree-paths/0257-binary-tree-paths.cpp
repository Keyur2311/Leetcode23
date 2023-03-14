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
  vector<string> v;
bool isLeaf(TreeNode *root)
{
    return !root->left && !root->right;
}
void rootToleaf(TreeNode *root, string s,vector<string> &v)
{
    if (isLeaf(root))
    {
        s = s + to_string(root->val);
        v.push_back(s);
        return;
    }

    if (root->left)
        rootToleaf(root->left, s +to_string(root->val)+ "->",v);
    if (root->right)
        rootToleaf(root->right, s +to_string(root->val)+ "->",v);
}
    vector<string> binaryTreePaths(TreeNode *root)
    {
        string s = "";
        vector<string> v;
        rootToleaf(root, s, v);
        return v;
    }
    
};