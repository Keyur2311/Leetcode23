class Solution {
public:
  bool validPath(int n, vector<vector<int>> &edges, int src, int des) {
    vector<vector<int>> adj;
    vector<bool> vis;
    adj.resize(n + 1);
    vis.resize(n + 1);

    for (int i = 0; i < edges.size(); i++) {
      int u = edges[i][0];
      int v = edges[i][1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    for (int i = 0; i <= n; i++)
      vis[i] = false;

    queue<int> q;
    q.push(src);
    vis[src] = 1;

    while (q.size() > 0) {
      int curr = q.front();
      q.pop();

      for (auto it : adj[curr]) {
        if (vis[it] == false) {
          q.push(it);
          vis[it] = true;
        }
      }
    }

    return vis[des];
  }
};