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
    void countGoodNodes(TreeNode *root, multiset<int, greater<int>> &st, int &count){
        if (root != NULL)
        {

            st.insert(root->val);
            countGoodNodes(root->left,st,count);
            int x = *(st.begin());
            if (x == root->val)
                count++;
            countGoodNodes(root->right,st,count);
            st.erase(st.find(root->val));
        }
    }
    
    int goodNodes(TreeNode *root) {
        multiset<int, greater<int>> st;
        int count = 0;
        countGoodNodes(root, st, count);
        return count;
    }
};