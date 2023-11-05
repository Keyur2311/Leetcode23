class Solution {
public:
  void dfs(int u, vector<int> adj[], vector<bool> &vis) {
    vis[u] = true;

    for (auto v : adj[u]) {
      if (!vis[v])
        dfs(v, adj, vis);
    }
  }
  int findCircleNum(vector<vector<int>> &arr) {

    int n = arr.size();
    int m = arr[0].size();
    int ans = 0;
    vector<int> adj[n + 1];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (arr[i][j]) {
          adj[i + 1].push_back(j + 1);
          adj[j + 1].push_back(i + 1);
        }
      }
    }

    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++) {
      if (vis[i] == false) {
        dfs(i, adj, vis);
        ans++;
      }
    }
    return ans;
  }
};