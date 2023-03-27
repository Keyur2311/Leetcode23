
class Solution
{
public:
    int LCS(string x, string y, int n, int m)
    {

        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for (int i = 0; i <= m; i++)
            dp[0][i] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (x[i - 1] == y[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][m];
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = (int)text1.size();
        int m = (int)text2.size();
        return LCS(text1, text2, n, m);
    }
};
