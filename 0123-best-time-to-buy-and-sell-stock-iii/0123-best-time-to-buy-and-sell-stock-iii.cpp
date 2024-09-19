// approach 1
// class Solution {
// public:
//   int maxProfit(vector<int> &prices) {
//     int buy1 = INT_MIN, sale1 = 0, buy2 = INT_MIN, sale2 = 0;
//     for (int i = 0; i < prices.size();i++) { 
//       buy1 = max(buy1, -prices[i]);         
//       sale1 = max(sale1, prices[i] + buy1); 
//       buy2 = max(buy2, sale1 - prices[i]);  
//       sale2 = max(sale2, prices[i] + buy2); 
//     }
//     return sale2;
//   }
// };

// approach 2

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
  int maxProfit(vector<int> &prices) {
    int n = (int)prices.size();

    vector<vector<vector<int>>> dp(n,
                                   vector<vector<int>>(2, vector<int>(3, -1)));
    return solve(0, 1, 2, prices, dp);
  }
};