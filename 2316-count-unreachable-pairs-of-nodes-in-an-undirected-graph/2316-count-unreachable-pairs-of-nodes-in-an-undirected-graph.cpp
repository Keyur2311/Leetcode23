class Solution
{
public:
    void dfs(int src, vector<int> adj[], vector<int> &vis, long long &ctr)
    {
        vis[src] = 1;
        ctr++;
        for (auto &it : adj[src])
        {
            int child = it;
            if (vis[child])
                continue;
            dfs(child, adj, vis, ctr);
        }
    }
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        int m = (int)edges.size();

        vector<int> adj[n];
        for (int i = 0; i < m; i++)
        {
            int a = edges[i][0], b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> vis(n, 0);
        long long ctr = 0;
        long long ans = ((long long)n * (n - 1)) / 2;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                ctr = 0;
                dfs(i, adj, vis, ctr);
                ans -= ((ctr * (ctr - 1)) / 2);
            }
        }

        return ans;
    }
};