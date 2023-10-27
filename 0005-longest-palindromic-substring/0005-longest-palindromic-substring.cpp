class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = (int)s.size();
         vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int length = 0, start = 0;
        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0, j = gap; j < n; i++, j++)
            {
                if (gap == 0)
                    dp[i][j] = 1;
                else if (gap == 1)
                {
                    if (s[i] == s[j])
                        dp[i][j] = 1;
                }
                else
                {
                    if (s[i] == s[j] && dp[i + 1][j - 1])
                        dp[i][j] = 1;
                }

                if (dp[i][j])
                {
                    if (gap + 1 > length)
                    {
                        length = gap + 1;
                        start = i;
                    }
                }
            }
        }

        string ans = "";
        int i = length;
        while (i--)
        {
            ans += s[start];
            start++;
        }
        return ans;
    }
};