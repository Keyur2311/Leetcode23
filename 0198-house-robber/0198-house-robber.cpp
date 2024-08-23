class Solution {
public:
  int solve(int idx, vector<int> &dp, vector<int> &nums) {

    if (idx >= (nums.size()))
      return 0;
    if (dp[idx] != -1)
      return dp[idx];
      
    int inc = 0, exc = 0;

    inc = nums[idx] + solve(idx + 2, dp, nums);
    exc = solve(idx + 1, dp, nums);

    return dp[idx] = max(inc, exc);
  }
  int rob(vector<int> &nums) {
    int n = (int)nums.size();
    vector<int> dp(n, -1);
    return solve(0, dp, nums);
  }
};