class Solution {
public:
  bool cycle = false;

  void dfs(int u, vector<int> graph[], vector<int> &vis) {
    vis[u] = 1;
    for (auto v : graph[u]) {
      if (vis[v] == 0)
        dfs(v, graph, vis);
      else if (vis[v] == 1)
        cycle = true;
    }
    vis[u] = 2;
  }
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> graph[numCourses];
    for (int i = 0; i < prerequisites.size(); i++) {
      int u = prerequisites[i][0];
      int v = prerequisites[i][1];
      graph[u].push_back(v);
    }

    vector<int> vis(numCourses, 0);
    cycle = false;
    for (int i = 0; i < numCourses; i++) {
      if (vis[i] == 0)
        dfs(i, graph, vis);
    }

    return !cycle;
  }
};