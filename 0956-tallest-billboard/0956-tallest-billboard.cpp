const int offset = 5000;
class Solution {
  int dp[21][2 * offset + 1];

public:
  int getAns(vector<int> &rods, int i, int diff) {

    if (i == (int)rods.size()) {
      if (diff == 0)
        return 0;
      return INT_MIN;
    }

    if (dp[i][diff + offset] != -1)
      return dp[i][diff + offset];

    int op1 = getAns(rods, i + 1, diff);
    int op2 = rods[i] + getAns(rods, i + 1, diff + rods[i]);
    int op3 = getAns(rods, i + 1, diff - rods[i]);

    return dp[i][diff + offset] = max({op1, op2, op3});
  }

  int tallestBillboard(vector<int> &rods) {

    memset(dp, -1, sizeof(dp));
    int ans = getAns(rods, 0, 0);
    if (ans < 0)
      return 0;
    return ans;
  }
};