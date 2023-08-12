class Solution {
public:
  static bool isValid(int i, int j, int n, int m) {
    return i >= 0 && i <= n - 1 && j >= 0 && j <= m - 1;
  }
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};

  int dfs(int a, int b, int n, int m, vector<vector<int>> &grid,
          vector<vector<int>> &vis, int ctr, int tctr) {

    if (grid[a][b] == 2)
      return (ctr == tctr ? 1 : 0);
    int count = 0;
    vis[a][b] = 1;
    for (int i = 0; i < 4; i++) {
      int x = a + dx[i];
      int y = b + dy[i];
      if (isValid(x, y, n, m) && grid[x][y] != -1 && !vis[x][y])
        count += dfs(x, y, n, m, grid, vis, ctr + 1, tctr);
    }

    vis[a][b] = 0;
    return count;
  }
  int uniquePathsIII(vector<vector<int>> &grid) {
    int n = (int)grid.size();
    int m = (int)grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    int ans = 0;
    int a = 0, b = 0, tempty = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1)
          a = i, b = j;
        if (grid[i][j] != -1)
          tempty++;
      }
    }
    
    return dfs(a, b, n, m, grid, vis, 1, tempty);
  }
};