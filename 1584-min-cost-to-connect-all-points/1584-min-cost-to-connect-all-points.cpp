class Solution {
public:
  struct DSU {
    vector<int> parent;
    vector<int> size;
    int components = 0;

    DSU(int n = -1) {
      if (n >= 0)
        init(n);
    }

    void init(int n) {
      parent.resize(n + 1);
      size.assign(n + 1, 1);
      components = n;

      for (int i = 0; i <= n; i++)
        parent[i] = i;
    }

    int find(int x) { return x == parent[x] ? x : parent[x] = find(parent[x]); }

    bool unite(int x, int y) {
      x = find(x);
      y = find(y);

      if (x == y)
        return false;

      if (x > y)
        swap(x, y);

      parent[y] = x;
      size[x] += size[y];
      components--;
      return true;
    }
  };

  int minCostConnectPoints(vector<vector<int>> &points) {

    int n = (int)points.size();
    vector<pair<int, pair<int, int>>> g;
    for (int i = 0; i < n; i++) {
      int x1 = points[i][0], y1 = points[i][1];
      for (int j = i + 1; j < n; j++) {
        int x2 = points[j][0], y2 = points[j][1];
        int c = abs(x1 - x2) + abs(y1 - y2);
        g.push_back({c, {i, j}});
      }
    }

    sort(g.begin(), g.end());
    int totcost = 0;

    DSU d1;
    d1.init(n + 1);

    for (auto edge : g) {
      int wt = edge.first;
      int u = edge.second.first;
      int v = edge.second.second;

      if (d1.find(u) == d1.find(v))
        continue;
      d1.unite(u, v);
      totcost += wt;
    }

    return totcost;
  }
};