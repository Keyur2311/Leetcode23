class Solution {
public:
  int minFallingPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int dp[n][m];

    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        if (i == n - 1 && j == m - 1)
          dp[i][j] = matrix[i][j];
        else if (i == n - 1)
          dp[i][j] = matrix[i][j];
        else {
          dp[i][j] = matrix[i][j];
          int val = dp[i + 1][j];
          if (i + 1 < n && j + 1 < m)
            val = min(val, dp[i + 1][j + 1]);
          if (i + 1 < n && j - 1 >= 0)
            val = min(val, dp[i + 1][j - 1]);

          dp[i][j] += val;
        }
      }
    }

    int ans = dp[0][0];
    for (int i = 0; i < m; i++)
      ans = min(ans, dp[0][i]);

    return ans;
  }
};