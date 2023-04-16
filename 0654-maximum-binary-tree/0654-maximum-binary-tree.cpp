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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums){
        vector<TreeNode *> st;

        for (auto &val : nums){
            TreeNode *curr = new TreeNode(val);
            while (!st.empty() && val > st.back()->val)
            {
                curr->left = st.back();
                st.pop_back();
            }

            if (!st.empty())
                st.back()->right = curr;
                
            st.push_back(curr);
        }
        return st.front();
    }
};
