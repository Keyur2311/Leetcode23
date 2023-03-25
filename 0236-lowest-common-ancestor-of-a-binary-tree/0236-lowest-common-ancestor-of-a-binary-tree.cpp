/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool getPath(TreeNode *root, TreeNode *node, vector<TreeNode *> &path)
    {
        if (root == NULL)
            return false;

        path.push_back(root);

        if (root == node)
            return true;

        if (getPath(root->left, node, path) || getPath(root->right, node, path))
            return true;

        path.pop_back();
        return false;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> a, b;
        if (!getPath(root, p, a) || !getPath(root, q, b))
            return NULL;

        TreeNode* ans = NULL;
        for (int i = 0; i < min((int)a.size(),(int)b.size()); i++)
        {
            if (a[i] == b[i])
               ans = a[i];
        }

        return ans;
    }
};


// get path for both nodes
// run loop for finding LCA