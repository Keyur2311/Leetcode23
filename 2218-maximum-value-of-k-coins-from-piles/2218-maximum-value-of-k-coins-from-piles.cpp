class Solution{
public:
    int solveDp(int i, int k, vector<vector<int>> &piles, vector<vector<int>> &dp){

        if (dp[i][k])
            return dp[i][k];

        if (i == piles.size() || k == 0)
            return 0;

        int res = solveDp(i + 1, k, piles, dp);
        int cur = 0;

        for (int j = 0; j < (int)piles[i].size() && j < k; j++)
        {
            cur += piles[i][j];
            res = max(res, solveDp(i + 1, k - (j + 1), piles, dp) + cur);
        }

        return dp[i][k] = res;
    }
    int maxValueOfCoins(vector<vector<int>> &piles, int k){
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        return solveDp(0, k, piles, dp);
    }
};