class Solution {
public:
  int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {

    int m = (int)edges.size();
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < m; i++) {
      int a = edges[i][0], b = edges[i][1], cost = edges[i][2];
      dist[a][b] = cost;
      dist[b][a] = cost;
    }

    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX)
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }

    int city = -1, ctr = n;

    for (int i = 0; i < n; i++) {
      int x = 0;
      for (int j = 0; j < n; j++) {
        if (i == j)
          continue;
        if (dist[i][j] <= distanceThreshold)
          x++;
      }
      if (x <= ctr) {
        city = i;
        ctr = x;
      }
    }

    return city;
  }
};