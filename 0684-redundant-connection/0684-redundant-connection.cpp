// APPROCH 1:- USING DFS CYCLE DETECTION
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

// APPROACH 2:- USING UNION FIND
class DSU {
    vector<int> par, rank;
public:
    DSU(int n) : par(n), rank(n) {
        iota(begin(par), end(par), 0);
    }
    int find(int x) {
        if(x == par[x]) return x;           // x is itself the parent of this component
        return par[x] = find(par[x]);       // update parent of x before returning for each call
    }
    bool Union(int x, int y) {
        auto xp = find(x), yp = find(y);    // find parents of x and y, i.e, representatives of components that x and y belong to
        if(xp == yp) return false;          // x and y already belong to same component - not possible to union
        return par[xp] = yp;                // union x and y by making parent common
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
        DSU ds(size(e)+1);
        for(auto& E : e) 
            if(!ds.Union(E[0], E[1])) return E;	// not possible to union - adding this edge was causing the cycle
        return { };    // un-reachable
    }
};
