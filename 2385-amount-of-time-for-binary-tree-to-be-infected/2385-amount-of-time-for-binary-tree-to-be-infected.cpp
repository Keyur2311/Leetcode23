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
  map<int, vector<int>> graph;

  void dfs(TreeNode *root, int par) {
    if (!root)
      return;
    if (par != -1) {
      graph[root->val].push_back(par);
      graph[par].push_back(root->val);
    }
    dfs(root->left, root->val);
    dfs(root->right, root->val);
  }

  int amountOfTime(TreeNode *root, int start) {

    dfs(root, -1);

    queue<pair<int, int>> q;
    q.push({start, 0});

    unordered_set<int> vis;
    vis.insert(start);
    int ans = 0;

    while (q.size() > 0) {
      auto topp = q.front();
      q.pop();
      ans = max(ans, topp.second);

      for (auto it : graph[topp.first]) {
        if (vis.count(it))
          continue;
        q.push({it, topp.second + 1});
        vis.insert(it);
      }
    }

    return ans;
  }
};