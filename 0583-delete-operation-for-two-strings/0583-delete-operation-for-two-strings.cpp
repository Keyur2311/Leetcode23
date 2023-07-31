class Solution {
public:
  int minDistance(string x, string y) {
    int n = (int)x.length();
    int m = (int)y.length();

    int dp[n + 1][m + 1];

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < m + 1; i++)
      dp[0][i] = 0;

    for (int i = 0; i < n + 1; i++)
      dp[i][0] = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (x[i - 1] == y[j - 1])
          dp[i][j] = 1 + dp[i - 1][j - 1];
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }

    return (n + m - (2 * dp[n][m]));
  }
};