class Solution {
public:
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};

  bool isValid(int i, int j, int n, int m) {
    return i >= 0 && i <= n - 1 && j >= 0 && j <= m - 1;
  }

  void calc(int i, int j, int n, int m, vector<vector<int>> &dp,
            vector<vector<int>> &matrix) {

    int mx = 0;
    for (int k = 0; k < 4; k++) {
      int x = i + dx[k];
      int y = j + dy[k];

      if (isValid(x, y, n, m) && matrix[x][y] > matrix[i][j] && dp[x][y] == 1) {
        calc(x, y, n, m, dp, matrix);
      }

      if (isValid(x, y, n, m) && matrix[x][y] > matrix[i][j])
        mx = max(mx, dp[x][y]);
    }

    dp[i][j] += mx;
  }

  int longestIncreasingPath(vector<vector<int>> &matrix) {
    int n = (int)matrix.size();
    int m = (int)matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 1));
    int ans = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (dp[i][j] > 1)
          continue;
        calc(i, j, n, m, dp, matrix);
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        ans = max(ans, dp[i][j]);
    }

    return ans;
  }
};