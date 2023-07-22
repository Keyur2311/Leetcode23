class Solution {
public:
  int dir[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1},
                 {2, 1},   {1, 2},   {-1, 2}, {-2, 1}};
  double dp[25][25][101];
  double knightProbability(int n, int k, int row,int column) {
    return find(n, k, row, column);
  }

  double find(int n, int k, int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= n)
      return 0;
    if (k == 0)
      return 1;

    if (dp[r][c][k] != 0)
      return dp[r][c][k];

    double rate = 0;
    for (int i = 0; i < 8; i++)
      rate += 0.125 * find(n, k - 1, r + dir[i][0], c + dir[i][1]);
    return dp[r][c][k] = rate;
  }
};