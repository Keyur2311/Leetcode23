class Solution {
public:
  int countServers(vector<vector<int>> &grid) {
    int n = (int)grid.size();
    int m = (int)grid[0].size();

    vector<int> rowcount(n, 0), colcount(m, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          rowcount[i]++;
          colcount[j]++;
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1 && (rowcount[i] > 1 || colcount[j] > 1))
          ans++;
      }
    }

    return ans;
  }
};