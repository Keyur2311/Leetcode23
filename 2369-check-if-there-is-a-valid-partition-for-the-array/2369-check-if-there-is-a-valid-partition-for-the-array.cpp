class Solution {
public:
  bool validPartition(vector<int> &nums) {
    int n = (int)nums.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 1;
    for (int i = n - 2; i >= 0; i--) {
      if (i + 2 == n) {
        if (nums[i] == nums[i + 1])
          dp[i] = dp[i + 2];
      } else if (i + 2 < n) {
        if (nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2])
          dp[i] = dp[i + 3];
        if (!dp[i] && nums[i] + 1 == nums[i + 1] && nums[i + 1] + 1 == nums[i + 2])
          dp[i] = dp[i + 3];
        if (!dp[i] && nums[i] == nums[i + 1])
          dp[i] = dp[i + 2];
      }
    }
      
    return (dp[0] == 1);
  }
};