class Solution {
public:
  int maxDistance(vector<vector<int>> &v) {
    int n = (int)v.size();

    int mn = -1, mx = -1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int sz = (int)v[i].size();
      if (i == 0)
        mn = v[i][0], mx = v[i][sz - 1];
      else {
        ans = max(ans, abs(v[i][0] - mx));
        ans = max(ans, abs(mn - v[i][sz - 1]));
        mn = min(mn, v[i][0]);
        mx = max(mx, v[i][sz - 1]);
      }
    }

    return ans;
  }
};