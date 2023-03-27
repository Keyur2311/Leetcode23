class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
         int row = grid.size(), col = grid[0].size();
    vector<vector<int>> dp(row, vector<int> (col, -1));
    
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(i == 0 && j == 0) dp[i][j] = grid[i][j];
            else {
                int left = INT_MAX, up = INT_MAX;
                if(i > 0) up = min(up, dp[i - 1][j]);
                if(j > 0) left = min(left, dp[i][j - 1]);
                
                dp[i][j] = min(up, left) + grid[i][j];
            }
        }
    }
    return dp[row - 1][col - 1];
    }
};