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

  bool isValid(int i, int j, int n, int m) {
    return i >= 0 && i <= n - 1 && j >= 0 && j <= m - 1;
  }
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};
  int maxAreaOfIsland(vector<vector<int>> &grid) {

    int n = (int)grid.size();
    int m = (int)grid[0].size();

    int tot = n * m, ctr = -1;

    DSU d(tot);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ctr++;
        if (grid[i][j] == 0)
          continue;
        for (int k = 0; k < 4; k++) {
          int x = i + dx[k];
          int y = j + dy[k];

          int val = (x * m) + y;

          if (isValid(x, y, n, m) && grid[x][y] == 1 &&
              d.find(ctr) != d.find(val))
            d.unite(ctr, val);
        }
      }
     
    }

    ctr = -1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         ctr++;
        if (grid[i][j] == 0)
          continue;
        ans = max(ans, d.size[d.find(ctr)]);
      }
    }

    return ans;
  }
};