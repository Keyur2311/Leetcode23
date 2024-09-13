class Solution {
public:
  bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target) {
    int n = (int)ghosts.size();

    int sdist = abs(target[0]) + abs(target[1]);

    for (auto g : ghosts) {
      int x = g[0], y = g[1];
      int dist = abs(g[0] - target[0]) + abs(g[1] - target[1]);
      if (dist <= sdist)
        return false;
    }
    return true;
  }
};
