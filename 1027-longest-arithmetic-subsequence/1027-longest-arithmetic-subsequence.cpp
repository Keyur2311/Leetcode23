class Solution{
public:
    int longestArithSeqLength(vector<int> &nums){
        int n = (int)nums.size();

        vector<vector<int>> dp(n, vector<int>(505, 1));
        int ans = 0;

        for (int i = 1; i < n; i++){
            for (int j = 0; j < i; j++){
                int diff = nums[i] - nums[j];
                if (diff < 0)
                    continue;
                dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
                ans = max(ans, dp[i][diff]);
            }
        }

        reverse(nums.begin(), nums.end());

        for (int i = 0; i < n; i++){
            for (int j = 0; j < 505; j++)
                dp[i][j] = 1;
        }

        for (int i = 1; i < n; i++){
            for (int j = 0; j < i; j++){
                int diff = nums[i] - nums[j];
                if (diff < 0)
                    continue;
                dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
                ans = max(ans, dp[i][diff]);
            }
        }

        return ans;
    }
};