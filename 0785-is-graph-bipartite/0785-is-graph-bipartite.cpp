class Solution {
public:
  bool dfs(int src, int c, vector<int> &color, vector<vector<int>> &graph) {
    color[src] = c;

    for (auto it : graph[src]) {
      if (color[it] == -1) {
        if (!dfs(it, c ^ 1, color, graph))
          return false;
      } else if (color[it] == color[src])
        return false;
    }
    return true;
  }

  bool isBipartite(vector<vector<int>> &graph) {

    int n = graph.size();
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++) {
      if (color[i] == -1) {
        if (!dfs(i, 0, color, graph))
          return false;
      }
    }
    return true;
  }
};