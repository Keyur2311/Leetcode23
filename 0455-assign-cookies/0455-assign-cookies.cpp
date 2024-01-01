class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    int n = (int)s.size();
    int m = (int)g.size();

    sort(s.begin(), s.end());
    sort(g.begin(), g.end());

    int i = 0, j = 0, ans = 0;
    while (i < m && j < n) {
      if (s[j] >= g[i]) {
        ans++;
        j++, i++;
      } else {
        j++;
      }
    }
    return ans;
  }
};