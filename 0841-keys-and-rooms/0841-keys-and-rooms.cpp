class Solution{
public:
    void dfs(int src, vector<int> adj[], vector<int> &vis)
    {
        vis[src] = 1;
        for (auto &it : adj[src])
        {
            if (!vis[it])
                dfs(it, adj, vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = (int)rooms.size();
        vector<int> adj[n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < (int)rooms[i].size(); j++)
            {
                adj[i].push_back(rooms[i][j]);
            }
        }

        vector<int> vis(n, 0);
        dfs(0, adj, vis);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                return false;
        }
        return true;
    }
};