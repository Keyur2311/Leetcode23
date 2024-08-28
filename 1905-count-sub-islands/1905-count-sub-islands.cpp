class Solution {
public:
  bool isValid(int i, int j, int n, int m) {
    return i >= 0 && i <= n - 1 && j >= 0 && j <= m - 1;
  }
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};

  void dfs(int i, int j, bool &ok, vector<vector<int>> &vis,
           vector<vector<int>> &arr, vector<vector<int>> &brr) {

    vis[i][j] = true;
    if (arr[i][j] == 0) {
      ok = false;
    }

    for (int k = 0; k < 4; k++) {
      int x = i + dx[k];
      int y = j + dy[k];

      int n = (int)arr.size();
      int m = (int)arr[0].size();

      if (isValid(x, y, n, m) && !vis[x][y] && brr[x][y] == 1)
        dfs(x, y, ok, vis, arr, brr);
    }
  }
  int countSubIslands(vector<vector<int>> &arr, vector<vector<int>> &brr) {
    int n = (int)arr.size();
    int m = (int)arr[0].size();

    int ans = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!vis[i][j] && brr[i][j] == 1) {
          bool ok = true;
          dfs(i, j, ok, vis, arr, brr);
          ans += (ok == true);
        }
      }
    }

    return ans;
  }
};