class Solution {
public:
    void dfs(int src, vector<pair<int, int>> adj[], vector<int> &vis)
    {
        vis[src] = 1;
        for (auto &it : adj[src])
        {
            int child = it.first, dis = it.second;
            if (vis[child])
                continue;
            
            dfs(child, adj, vis);
        }
    }
    
    int minScore(int n, vector<vector<int>> &roads)
    {
        int m = (int)roads.size();
        int min_distance = INT_MAX;
        vector<pair<int, int>> adj[n + 1];
        for (int i = 0; i < m; i++)
        {
            int a = roads[i][0], b = roads[i][1], dis = roads[i][2];
            adj[a].push_back({b, dis});
            adj[b].push_back({a, dis});
        }
        
        vector<int> vis(n + 1, 0);
        dfs(1, adj, vis);

        for (int i = 0; i < m; i++)
        {
            int a = roads[i][0], b = roads[i][1], dis = roads[i][2];
            if (vis[a] && vis[b])
                min_distance = min(min_distance, dis);
        }
        
        return min_distance;
    }
};