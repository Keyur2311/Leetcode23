class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    int n = (int)s.size();

    vector<int> dp(n + 1, 0);
    dp[n] = 1;

    for (int i = n - 1; i >= 0; i--) {
      for (auto word : wordDict) {
        int wordsize = (int)word.size();
        if (i + wordsize <= n && s.substr(i, wordsize) == word)
          dp[i] = dp[i + wordsize];
        if (dp[i])
          break;
      }
    }

    return dp[0];
  }
};