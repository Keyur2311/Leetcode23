class Solution {
public:
  int minProcessingTime(vector<int> &p, vector<int> &t) {
    sort(p.begin(), p.end());
    sort(t.rbegin(), t.rend());

    int ans = 0;
    int n = (int)t.size();

    for (int i = 0; i < n; i += 4)
      ans = max(ans, t[i] + (p[i / 4]));

    return ans;
  }
};
