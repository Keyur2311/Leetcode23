class Solution {
public:
  long long minimumCost(string source, string target, vector<char> &o,
                        vector<char> &c, vector<int> &cost) {
    int v = 26;
    vector<int> adj[v];

    long long int INF = (long long)(1e12 + 10);

    vector<vector<long long>> dist(v, vector<long long>(v, INF));

    int n = (int)o.size();
    for (int i = 0; i < n; i++) {
      int s = (int)(o[i] - 'a');
      int d = (int)(c[i] - 'a');
      dist[s][d] = min(dist[s][d], (long long int)cost[i]);
    }

    for (int i = 0; i < v; i++) {
      for (int j = 0; j < v; j++) {
        if (i == j)
          dist[i][j] = 0;
      }
    }

    for (int k = 0; k < v; k++) {
      for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }

    int sz = (int)source.size();
    long long ans = 0;
    for (int i = 0; i < sz; i++) {
      int s = (int)(source[i] - 'a');
      int d = (int)(target[i] - 'a');
      if (dist[s][d] == INF)
        return -1;
      ans += dist[s][d];
    }

    return ans;
  }
};