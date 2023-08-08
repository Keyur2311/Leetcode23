class Solution {
public:
  bool isValid(int i, int j, int n, int m) {
    return i >= 0 && i <= n - 1 && j >= 0 && j <= m - 1;
  }
    
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};

  void getDistance(int n, queue<pair<int, int>> &q, vector<vector<int>> &grid,
                   vector<vector<int>> &dis, vector<vector<bool>> &vis) {

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
          if (isValid(x, y, n, n) && !vis[x][y]) {
            q.push({x, y});
            vis[x][y] = true;
          }
        }
      }
      lvl++;
    }
  }
    
  int findSf(int n, vector<vector<int>> &dis) {

    priority_queue<pair<int, pair<int, int>>> pq;
    vector<vector<bool>> vis(n, vector<bool>(n));
    pq.push({dis[0][0], {0, 0}});
    vis[0][0] = true;

    int ans = 1e9;

    while (!pq.empty()) {
      auto it = pq.top();
      pq.pop();
      int a = it.second.first, b = it.second.second;
      ans = min(ans, dis[a][b]);
        
      if (a == n - 1 && b == n - 1)
        return ans;
      for (int i = 0; i < 4; i++) {
        int x = a + dx[i];
        int y = b + dy[i];
        if (isValid(x, y, n, n) && !vis[x][y]) {
          vis[x][y] = true;
          pq.push({dis[x][y], {x, y}});
        }
      }
    }
      
    return ans;
  }
    
  int maximumSafenessFactor(vector<vector<int>> &grid) {
    int n = (int)grid.size();

    queue<pair<int, int>> q;
    vector<vector<int>> dis(n, vector<int>(n));
    vector<vector<bool>> vis(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          q.push({i, j});
          vis[i][j] = true;
        }
      }
    }
      
    getDistance(n, q, grid, dis, vis);
    int ans = findSf(n, dis);
    return ans;
      
  }
};