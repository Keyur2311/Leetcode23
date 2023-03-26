class Solution
{
public:
    int cycleStart = -1;
    void dfs(int curr, int par, vector<int> adj[], vector<int> &vis, set<int> &cycle)
    {
        if (vis[curr])
        {
            cycleStart = curr;
            return;
        }
        vis[curr] = 1;
        for (auto child : adj[curr])
        {
            if (child == par)
                continue;
            if (cycle.empty())
                dfs(child, curr, adj, vis, cycle);
            if (cycleStart != -1)
                cycle.insert(curr);
            if (curr == cycleStart)
            {
                cycleStart = -1;
                return;
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        int m = n;

        vector<int> adj[n + 1];
        for (int i = 0; i < m; i++)
        {
            int a = edges[i][0], b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> vis(n + 1, 0);
        set<int> cycle;
        dfs(1, -1, adj, vis, cycle);

        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            if (cycle.count(edges[i][0]) && cycle.count(edges[i][1]))
                res = edges[i];
        }

        return res;
    }
};
