// approach 1
// class Solution {
// public:
//     int maxProfit(vector<int> &prices, int fee) {
//         int buy = INT_MIN, sell = 0;

//         for (auto price : prices) {
//             buy = max(buy, sell - price);
//             sell = max(sell, price + buy - fee);
//         }
//         return sell;
//     }
// };
//approach 2
class Solution {
public:
  int solve(int idx, int buy, int fee, vector<int> &prices,
            vector<vector<int>> &dp) {

    if (idx >= (int)prices.size())
      return 0;

    if (dp[idx][buy] != -1)
      return dp[idx][buy];

    int profit = 0;
    if (buy) {
      int op1 = -prices[idx] + solve(idx + 1, false, fee, prices, dp);
      int op2 = solve(idx + 1, true, fee, prices, dp);
      profit = max(op1, op2);
    } else {
      int op1 = -fee + prices[idx] + solve(idx + 1, true, fee, prices, dp);
      int op2 = solve(idx + 1, false, fee, prices, dp);
      profit = max(op1, op2);
    }

    return dp[idx][buy] = profit;
  }
  int maxProfit(vector<int> &prices, int fee) {
    int n = (int)prices.size();

    vector<vector<int>> dp(n, vector<int>(2, -1));
    return solve(0, 1, fee, prices, dp);
  }
};