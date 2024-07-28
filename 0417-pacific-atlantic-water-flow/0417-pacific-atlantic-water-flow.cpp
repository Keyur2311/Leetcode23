class Solution {
public:
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};

  void dfs(int i, int j, vector<vector<bool>> &canReach, vector<vector<int>> &heights) {
    canReach[i][j] = true;
    int n = heights.size();
    int m = heights[0].size();
    for (int k = 0; k < 4; k++) {
      int x = i + dx[k];
      int y = j + dy[k];
      if (x >= 0 && x < n && y >= 0 && y < m && !canReach[x][y] && heights[x][y] >= heights[i][j]) {
        dfs(x, y, canReach, heights);
      }
    }
  }

  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    int n = heights.size();
    if (n == 0) return {};
    int m = heights[0].size();

    vector<vector<bool>> pacific(n, vector<bool>(m, false));
    vector<vector<bool>> atlantic(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
      dfs(i, 0, pacific, heights);   
      dfs(i, m - 1, atlantic, heights); 
    }
    for (int j = 0; j < m; j++) {
      dfs(0, j, pacific, heights);   
      dfs(n - 1, j, atlantic, heights); 
    }

    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (pacific[i][j] && atlantic[i][j]) {
          ans.push_back({i, j});
        }
      }
    }
    return ans;
  }
};
