class Solution {
public:
  void dfs(int src, vector<int> adj[], vector<int> &vis, unordered_set<int> &st,
           int &ctr) {

    vis[src] = 1;

    for (auto child : adj[src]) {
      if (vis[child] || st.count(child))
        continue;
      ctr++;
      dfs(child, adj, vis, st, ctr);
    }
  }
  int reachableNodes(int n, vector<vector<int>> &edges,
                     vector<int> &restricted) {
    unordered_set<int> st;
    for (auto node : restricted)
      st.insert(node);

    vector<int> adj[n];
    for (int i = 0; i < n - 1; i++) {
      int x = edges[i][0], y = edges[i][1];
      adj[x].push_back(y);
      adj[y].push_back(x);
    }

    vector<int> vis(n, 0);
    int ctr = 1;
    dfs(0, adj, vis, st, ctr);

    return ctr;
  }
};