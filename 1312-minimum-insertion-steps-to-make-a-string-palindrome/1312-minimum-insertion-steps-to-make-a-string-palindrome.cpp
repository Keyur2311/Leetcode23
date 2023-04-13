class Solution {
public:
    int minInsertions(string s) {
         int n = s.size();
        int dp[n][n];
        memset(dp, 0, sizeof(n));

        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0, j = gap; j < n; j++, i++)
            {
                if (gap == 0)
                    dp[i][j] = 1;
                else if (gap == 1)
                {
                    if (s[i] == s[j])
                        dp[i][j] = 2;
                    else
                        dp[i][j] = 1;
                }
                else
                {
                    if (s[i] == s[j])
                        dp[i][j] = 2 + dp[i + 1][j - 1];
                    else
                        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
       
        return n - dp[0][n-1];
    }
};