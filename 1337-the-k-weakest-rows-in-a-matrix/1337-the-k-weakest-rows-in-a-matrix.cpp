class Solution {
public:
  vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
    priority_queue<pair<int, int>> pq;
    int n = (int)mat.size(), m = (int)mat[0].size();
    for (int i = 0; i < n; i++) {
      int ctr = 0;
      for (int j = 0; j < m; j++)
        ctr += (mat[i][j] == 1 ? 1 : 0);
      pq.push({ctr, i});
      if (pq.size() > k)
        pq.pop();
    }

    vector<int> v;
    while (!pq.empty()) {
      v.push_back(pq.top().second);
      pq.pop();
    }
    reverse(v.begin(),v.end());
    return v;
  }
};