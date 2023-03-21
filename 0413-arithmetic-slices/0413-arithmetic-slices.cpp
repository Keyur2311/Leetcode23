class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &arr) {

        int n = arr.size();
        if (n <= 2)
            return 0;

        vector<int> dp(n, 0);
        int ans = 0;
        for (int i = 2; i < n; i++){
            if (arr[i] - arr[i - 1] == (arr[i - 1] - arr[i - 2]))
                dp[i] = 1 + dp[i - 1];

            ans += dp[i];
        }

        return ans;
    }
};