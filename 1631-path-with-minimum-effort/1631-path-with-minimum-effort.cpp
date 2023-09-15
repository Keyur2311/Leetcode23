class Solution {
public:
  bool isValid(int i, int j, int n, int m) {
    return i >= 0 && i <= n - 1 && j >= 0 && j <= m - 1;
  }
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};

  int minimumEffortPath(vector<vector<int>> &heights) {
    int n = (int)heights.size();
    int m = (int)heights[0].size();

    if (n == 1 && m == 1)
      return 0;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;

    pq.push({heights[0][0], {0, 0}});
    vector<vector<int>> dis(n, vector<int>(m, INT_MAX));

    while (!pq.empty()) {
      auto tp = pq.top();
      pq.pop();
      int a = tp.second.first, b = tp.second.second;
      int d = tp.first;

      for (int i = 0; i < 4; i++) {
        int x = a + dx[i];
        int y = b + dy[i];

        if (isValid(x, y, n, m)) {

          int xt = abs(heights[a][b] - heights[x][y]);
          if (dis[a][b] != INT_MAX)
            xt = max(dis[a][b], xt);

          if (dis[x][y] > xt) {
            dis[x][y] = xt;
            pq.push({xt, {x, y}});
          }
        }
      }
    }

    return dis[n - 1][m - 1];
  }
};