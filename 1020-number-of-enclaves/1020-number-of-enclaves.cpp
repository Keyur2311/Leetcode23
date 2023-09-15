class Solution {
public:
  bool isValid(int i, int j, int n, int m) {
    return i >= 0 && i <= n - 1 && j >= 0 && j <= m - 1;
  }
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};

  void dfs(int i, int j, bool &ok, int &ctr, int n, int m,
           vector<vector<int>> &vis, vector<vector<int>> &grid) {

    vis[i][j] = 1;
    ctr++;

    if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
      ok = false;

    for (int k = 0; k < 4; k++) {
      int x = i + dx[k];
      int y = j + dy[k];
      if (isValid(x, y, n, m) && grid[x][y] == 1 && !vis[x][y])
        dfs(x, y, ok, ctr, n, m, vis, grid);
    }
  }

  int numEnclaves(vector<vector<int>> &grid) {

    int n = (int)grid.size(), m = (int)grid[0].size();

    int ans = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 0 || vis[i][j])
          continue;
        bool ok = true;
        int ctr = 0;
        dfs(i, j, ok, ctr, n, m, vis, grid);
        ans += (ok ? ctr : 0);
      }
    }

    return ans;
  }
};