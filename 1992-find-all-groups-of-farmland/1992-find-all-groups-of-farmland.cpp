class Solution {
public:
  bool isValid(int i, int j, int n, int m) {
    return i >= 0 && i <= n - 1 && j >= 0 && j <= m - 1;
  }
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};

  void dfs(int i, int j, vector<int> &a, vector<vector<int>> &vis,
           vector<vector<int>> &arr) {

    vis[i][j] = true;
    a[0] = min(a[0], i);
    a[1] = min(a[1], j);

    a[2] = max(a[2], i);
    a[3] = max(a[3], j);

    for (int k = 0; k < 4; k++) {
      int x = i + dx[k];
      int y = j + dy[k];

      int n = (int)arr.size();
      int m = (int)arr[0].size();

      if (isValid(x, y, n, m) && !vis[x][y] && arr[x][y] == 1)
        dfs(x, y, a, vis, arr);
    }
  }
  vector<vector<int>> findFarmland(vector<vector<int>> &arr) {
    int n = (int)arr.size();
    int m = (int)arr[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!vis[i][j] && arr[i][j] == 1) {
          vector<int> a = {INT_MAX, INT_MAX, -1, -1};
          dfs(i, j, a, vis, arr);
          if (a[0] == INT_MAX)
            continue;
          ans.push_back(a);
        }
      }
    }

    return ans;
  }
};