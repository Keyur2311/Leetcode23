//approach 1 
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = (int)prices.size();

//         int bd = 0, sd = 0, profit = 0;

//         for (int i = 1; i < n; i++) {
//             if (prices[i] >= prices[i - 1])
//                 sd++;
//             else {
//                 profit += prices[sd] - prices[bd];
//                 bd = sd = i;
//             }
//         }

//         profit += prices[sd] - prices[bd];

//         return profit;
//     }
// };
//approach 2 :- recursion and dp
class Solution {
public:
  int solve(int idx, int buy, vector<int> &prices, vector<vector<int>> &dp) {

    if (idx >= (int)prices.size())
      return 0;

    if (dp[idx][buy] != -1)
      return dp[idx][buy];

    int profit = 0;
    if (buy) {
      int op1 = -prices[idx] + solve(idx + 1, false, prices, dp);
      int op2 = solve(idx + 1, true, prices, dp);
      profit = max(op1, op2);
    } else {
      int op1 = prices[idx] + solve(idx + 1, true, prices, dp);
      int op2 = solve(idx + 1, false, prices, dp);
      profit = max(op1, op2);
    }

    return dp[idx][buy] = profit;
  }
  int maxProfit(vector<int> &prices) {
    int n = (int)prices.size();

    vector<vector<int>> dp(n, vector<int>(2, -1));
    return solve(0, 1, prices, dp);
  }
};