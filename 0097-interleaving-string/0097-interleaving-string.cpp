class Solution {
public:
  int solve(int i, int j, int k, string s1, string s2, string s3,
             vector<vector<int>> &dp) {

    if (i < 0 && j < 0 && k < 0)
      return 1;

    if (i >= 0 && j >= 0 && dp[i][j] != -1)
      return dp[i][j];

    if (i >= 0 && s1[i] == s3[k] && j >= 0 && s2[j] == s3[k])
      return dp[i][j] = (solve(i - 1, j, k - 1, s1, s2, s3, dp) ||
                         solve(i, j - 1, k - 1, s1, s2, s3, dp));
    else if (i >= 0 && s1[i] == s3[k])
      return solve(i - 1, j, k - 1, s1, s2, s3, dp);
    else if (j >= 0 && s2[j] == s3[k])
      return solve(i, j - 1, k - 1, s1, s2, s3, dp);
    else
      return 0;
  }
  bool isInterleave(string s1, string s2, string s3) {
    int n = (int)s1.size(), m = (int)s2.size(), x = (int)s3.size();

    if (x != m + n)
      return false;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1 , -1));
    return (bool)solve(n - 1, m - 1, x - 1, s1, s2, s3, dp);
  }
};