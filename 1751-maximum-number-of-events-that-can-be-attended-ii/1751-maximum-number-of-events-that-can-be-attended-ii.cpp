class Solution {
public:
  static bool cmp(const vector<int> &a, const vector<int> &b) {
    return a[1] < b[1];
  }

  int help(vector<vector<int>> &e, int k, int i, vector<vector<int>> &dp) {
    if (i >= e.size() || k == 0)
      return 0;
    if (dp[i][k] != -1)
      return dp[i][k];

    vector<int> temp = {e[i][1], INT_MAX, INT_MAX};
    int in = upper_bound(e.begin(), e.end(), temp) - e.begin();
    int ans = max(help(e, k, i + 1, dp), e[i][2] + help(e, k - 1, in, dp));

    return dp[i][k] = ans;
  }
  int maxValue(vector<vector<int>> &e, int k) {
    sort(e.begin(), e.end());
    vector<vector<int>> dp(e.size(), vector<int>(k + 1, -1));
    return help(e, k, 0, dp);
  }
};