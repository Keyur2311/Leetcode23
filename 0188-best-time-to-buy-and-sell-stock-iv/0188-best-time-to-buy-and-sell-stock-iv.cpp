class Solution {
public:
  int solve(int idx, int buy, int cap, vector<int> &prices,
            vector<vector<vector<int>>> &dp) {

    if (idx >= (int)prices.size() || cap == 0)
      return 0;

    if (dp[idx][buy][cap] != -1)
      return dp[idx][buy][cap];

    int profit = 0;
    if (buy) {
      int op1 = -prices[idx] + solve(idx + 1, false, cap, prices, dp);
      int op2 = solve(idx + 1, true, cap, prices, dp);
      profit = max(op1, op2);
    } else {
      int op1 = prices[idx] + solve(idx + 1, true, cap - 1, prices, dp);
      int op2 = solve(idx + 1, false, cap, prices, dp);
      profit = max(op1, op2);
    }

    return dp[idx][buy][cap] = profit;
  }
  int maxProfit(int k, vector<int> &prices) {
    int n = (int)prices.size();

    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
    return solve(0, 1, k, prices, dp);
  }
};