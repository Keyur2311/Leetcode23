class Solution {
public:
  bool isValid(int i, int j, int n, int m) {
    return i >= 0 && i <= n - 1 && j >= 0 && j <= m - 1;
  }

  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};

  void getDistance(int n, int m, queue<pair<int, int>> &q,
                   vector<vector<int>> &grid, vector<vector<int>> &dis,
                   vector<vector<bool>> &vis) {

    int lvl = 0;
    while (!q.empty()) {
      int sz = q.size();

      while (sz--) {
        auto p = q.front();
        q.pop();
        int a = p.first, b = p.second;
        dis[a][b] = lvl;

        for (int i = 0; i < 4; i++) {
          int x = a + dx[i];
          int y = b + dy[i];
          if (isValid(x, y, n, m) && !vis[x][y]) {
            q.push({x, y});
            vis[x][y] = true;
          }
        }
      }
      lvl++;
    }
  }
  vector<vector<int>> updateMatrix(vector<vector<int>> &grid) {
    int n = (int)grid.size();
    int m = (int)grid[0].size();

    queue<pair<int, int>> q;
    vector<vector<int>> dis(n, vector<int>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 0) {
          q.push({i, j});
          vis[i][j] = true;
        }
      }
    }

    getDistance(n, m, q, grid, dis, vis);
    return dis;
  }
};