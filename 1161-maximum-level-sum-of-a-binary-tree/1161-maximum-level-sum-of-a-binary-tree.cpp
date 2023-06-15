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
    int maxLevelSum(TreeNode *root){
        queue<TreeNode *> q;
        q.push(root);

        vector<int> v;
        while ((int)q.size() > 0){
            
            int ctr = (int)q.size();
            int sum = 0;
            
            while (ctr--){
                TreeNode *temp = q.front();
                q.pop();
                sum += (temp->val);

                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            
            v.push_back(sum);
        }

        int mx = INT_MIN;
        for (auto &val : v)
            mx = max(mx, val);

        for (int i = 0; i < (int)v.size(); i++){
            if (mx == v[i])
                return i + 1;
        }

        return 1;
    }
};