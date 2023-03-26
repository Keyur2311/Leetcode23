class Solution
{
public:
    void dfs(int src, int par, vector<int> &parent, vector<int> adj[], vector<int> &vis, vector<int> &path)
    {

        vis[src] = 1;
        parent[src] = par;
        for (auto it : adj[src])
        {
            if (!vis[it])
                dfs(it, src, parent, adj, vis, path);
            else if (par != it && path.size()==0)
            {
                int curr = src;
                path.push_back(curr);

                while (curr!=-1 && parent[curr] != it)
                {
                    curr = parent[curr];
                    path.push_back(curr);
                }
                path.push_back(it);
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

        vector<int> vis(n + 1, 0), parent(n + 1, -1);
        vector<int> path;
        dfs(1, -1, parent, adj, vis, path);

        vector<int> res;
        set<int> st(path.begin(), path.end());
        for (int i = 0; i < n; i++)
        {
            if (st.count(edges[i][0]) && st.count(edges[i][1]))
                res = edges[i];
        }

        return res;
    }
};