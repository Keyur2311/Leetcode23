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
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;

        return countPaths(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }

private:

    int countPaths(TreeNode* node, long long targetSum) {
        if (!node) return 0;
      
        int paths = (node->val == targetSum) ? 1 : 0;

        paths += countPaths(node->left, targetSum - node->val);
        paths += countPaths(node->right, targetSum - node->val);

        return paths;
    }
};
