class Solution {
public:
  int minExtraChar(string s, vector<string> &dictionary) {

    int n = (int)s.size();

    vector<int> dp(n + 1, 0);

    for (int i = n - 1; i >= 0; i--) {
      int mx = 0;
      for (auto dictword : dictionary) {
        int wordsize = (int)dictword.size();
        if (i + wordsize <= n && s.substr(i, wordsize) == dictword) {
          mx = max(mx, wordsize + dp[i + wordsize]);
        }
      }
      dp[i] = max(mx,dp[i+1]);
    }
    return n - dp[0];
  }
};