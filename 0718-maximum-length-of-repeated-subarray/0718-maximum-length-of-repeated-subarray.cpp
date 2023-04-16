class Solution{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2){
        int n = (int)nums1.size();
        int m = (int)nums2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++){
                
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 0;

                if (dp[i][j] > ans)
                    ans = dp[i][j];
            }
        }
        return ans;
    }
};