class Solution {
public:
  int minimumDeleteSum(string x, string y) {
    int n = (int)x.length();
    int m = (int)y.length();

    int dp[n + 1][m + 1];

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
      dp[i][0] = dp[i - 1][0] + x[i - 1];

    for (int i = 1; i <= m; i++)
      dp[0][i] = dp[0][i - 1] + y[i - 1];

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (x[i - 1] == y[j - 1])
          dp[i][j] = dp[i - 1][j - 1];
        else
          dp[i][j] = min(x[i - 1] + dp[i - 1][j], y[j - 1] + dp[i][j - 1]);
      }
    }

    return dp[n][m];
  }
};