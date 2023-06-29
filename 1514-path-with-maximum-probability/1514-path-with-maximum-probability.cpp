class Solution {
public:
  double maxProbability(int n, vector<vector<int>> &edges, vector<double> &pro,
                        int start, int end) {

    vector<vector<pair<int, double>>> graph(n);
    for (int i = 0; i < edges.size(); i++) {
      graph[edges[i][0]].push_back({edges[i][1], pro[i]});
      graph[edges[i][1]].push_back({edges[i][0], pro[i]});
    }

    vector<int> seen(n, 0);
    vector<double> dis(n, (double)0.0);
    priority_queue<pair<double, int>> pq;

    pq.push({(double)1.0, start});
    dis[start] = (double)1.0;

    while (pq.size() > 0) {
      auto top = pq.top();
      pq.pop();
      double prob = top.first;
      int node = top.second;

      if (seen[node])
        continue;
      seen[node] = 1;

      for (auto &it : graph[node]) {
        if (dis[it.first] < it.second * prob) {
          dis[it.first] = it.second * prob;
          pq.push({dis[it.first], it.first});
        }
      }
    }

    return dis[end];
  }
};
