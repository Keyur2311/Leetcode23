class Solution {
public:
  bool cycle = false;

  void dfs(int u, vector<int> graph[], vector<int> &vis, stack<int> &st) {
    vis[u] = 1;
    for (auto v : graph[u]) {
      if (vis[v] == 0)
        dfs(v, graph, vis, st);
      else if (vis[v] == 1)
        cycle = true;
    }
    vis[u] = 2;
    st.push(u);
  }

  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> graph[numCourses];
    for (int i = 0; i < prerequisites.size(); i++) {
      int u = prerequisites[i][0];
      int v = prerequisites[i][1];
      graph[v].push_back(u);
    }

    stack<int> ans;
    vector<int> vis(numCourses, 0);
    cycle = false;
    for (int i = 0; i < numCourses; i++) {
      if (vis[i] == 0)
        dfs(i, graph, vis, ans);
    }

    vector<int> v;
    if (cycle)
      return v;

    while (!ans.empty()) {
      v.push_back(ans.top());
      ans.pop();
    }
    return v;
  }
};