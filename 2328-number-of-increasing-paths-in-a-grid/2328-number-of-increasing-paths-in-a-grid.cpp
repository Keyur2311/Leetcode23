class Solution{
public:

    bool isValid(int i, int j, int n, int m) { return i >= 0 && i <= n - 1 && j >= 0 && j <= m - 1; }
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
   const int M = 1000000007;

    int dfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (dp[r][c] != -1)
            return dp[r][c];

        long long int ctr = 1;
        int n = (int)grid.size();
        int m = (int)grid[0].size();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (isValid(nr, nc, n, m) && grid[nr][nc] > grid[r][c])
                ctr = ((ctr % M) + dfs(nr, nc, grid, dp) % M) % M;
        }

        return  dp[r][c] = ctr;
    }
    int countPaths(vector<vector<int>> &grid)
    {
        int n = (int)grid.size();
        int m = (int)grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        long long int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                ans = ((ans % M) + (dfs(i, j, grid, dp)) % M) % M;
        }

        return (int)ans%M;
    }
};
