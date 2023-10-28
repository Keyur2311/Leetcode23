class Solution {
public:
  int lengthOfLongestSubsequence(vector<int> &nums, int target) {
    int n = (int)nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    for (int i = 0; i < n + 1; i++)
      dp[i][0] = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= target; j++) {

        dp[i][j] = dp[i - 1][j];

        if (j >= nums[i - 1] && dp[i - 1][j - nums[i - 1]] != -1)
          dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - nums[i - 1]]);
      }
    }

    return dp[n][target];
  }
};