class Solution {
public:
  int maxScore(string s) {
    int n = (int)s.size();

    int ans = 0;
    for (int i = 1; i < n; i++) {
      int x = count(s.begin(), s.begin() + i, '0');
      int y = count(s.begin() + i, s.end(), '1');
      ans = max(ans, x + y);
    }

    return ans;
  }
};