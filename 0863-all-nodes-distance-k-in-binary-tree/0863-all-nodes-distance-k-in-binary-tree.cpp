/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
  vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    dfs(root, -1);
    queue<pair<int, int>> q;
    q.push({target->val, 0});

    unordered_set<int> vis;
    vis.insert(target->val);

    map<int, int> dis;
      dis[target->val] = 0;

    while (q.size() > 0) {
      auto topp = q.front();
      q.pop();

      for (auto it : graph[topp.first]) {
        if (vis.count(it))
          continue;
        q.push({it, topp.second + 1});
        vis.insert(it);
        dis[it] = topp.second + 1;
      }
    }

    vector<int> ans;
    for (auto it : dis) {
      if (it.second == k)
        ans.push_back(it.first);
    }
    return ans;
  }
};