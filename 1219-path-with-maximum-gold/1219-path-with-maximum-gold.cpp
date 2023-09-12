class Solution {
public:
  bool isValid(int i, int j, int n, int m) {
    return i >= 0 && i <= n - 1 && j >= 0 && j <= m - 1;
  }
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};
    
  void solve(int i, int j, int n, int m, int &tot, int &ans,
             vector<vector<int>> &vis, vector<vector<int>> &grid) {

    ans = max(ans, tot);
    vis[i][j] = 1;

    for (int k = 0; k < 4; k++) {
      int x = i + dx[k];
      int y = j + dy[k];
      if (isValid(x, y, n, m) && !vis[x][y] && grid[x][y] != 0) {
        tot += grid[x][y];
        solve(x, y, n, m, tot, ans, vis, grid);
        tot -= grid[x][y];
      }
    }
    vis[i][j] = 0;
      
  }
  int getMaximumGold(vector<vector<int>> &grid) {
    int n = (int)grid.size(), m = (int)grid[0].size();

    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] != 0) {
          vector<vector<int>> vis(n, vector<int>(m, 0));
          int tot = grid[i][j];
          solve(i, j, n, m, tot, ans, vis, grid);
        }
      }
    }

    return ans;
  }
};