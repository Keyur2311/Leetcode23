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

    int findBottomLeftValue(TreeNode *root){
        vector<int> ans;
        queue<TreeNode *> q;
        q.push(root);

        while (q.size() > 0) {
            int sz = q.size();

            while (sz--){
                TreeNode *curr = q.front();
                q.pop();

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);

                ans.push_back(curr->val);
            }
            if (q.size() > 0)
                ans.clear();
        }
        return ans[0];
    }
};