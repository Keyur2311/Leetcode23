class Solution {
public:
  void solve(int src, int target, vector<int> &curr, vector<vector<int>> &ans,
             vector<vector<int>> &graph) {
    if (src == target) {
      ans.push_back(curr);
      return;
    }
    for (auto child : graph[src]) {
      curr.push_back(child);
      solve(child, target, curr, ans, graph);
      curr.pop_back();
    }
  }
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {

    vector<vector<int>> ans;
    vector<int> curr;
    int src = 0, target = (int)graph.size() - 1;
    curr.push_back(0);
    solve(src, target, curr, ans, graph);
    return ans;
  }
};