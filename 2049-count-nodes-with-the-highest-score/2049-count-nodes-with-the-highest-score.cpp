class Solution {
public:
  void dfs(int src, vector<int> adj[], vector<int> &dp, vector<int> &vis) {
    vis[src] = 1;

    for (auto child : adj[src]) {
      if (vis[child])
        continue;
      dfs(child, adj, dp, vis);
      dp[src] += dp[child];
    }

    dp[src] += 1;
  }

  int countHighestScoreNodes(vector<int> &parents) {
    int n = (int)parents.size();

    vector<int> adj[n];
    for (int i = 0; i < n; i++) {
      if (parents[i] != -1)
        adj[parents[i]].push_back(i);
    }

    vector<int> dp(n, 0), vis(n, 0);

    dfs(0, adj, dp, vis);

    int ans = 0;
    long long int mx = 0;

    vector<long long int> vals;
    for (int i = 0; i < n; i++) {
      vector<int> temp;
      long long int tot = 1;
      for (auto it : adj[i])
        temp.push_back(dp[it]);
      int left = n - dp[i];
      if (left)
        temp.push_back(left);

      for (auto it : temp)
        tot *= (1LL * it);
      vals.push_back(tot);
      mx = max(mx, tot);
    }

    for (auto it : vals) {
      if (it == mx)
        ans++;
    }

    return ans;
  }
};