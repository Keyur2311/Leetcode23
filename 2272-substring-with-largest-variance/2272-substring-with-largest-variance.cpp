class Solution {
public:
  int largestVariance(string s) {
    int res = 0;
    unordered_set<char> unique(begin(s), end(s));
    for (char a : unique) {
      for (char b : unique) {
        int ans = 0, has_b = 0, first_b = 0;

        for (char ch : s) {
          ans += ch == a;
          if (ch == b) {
            has_b = true;
            if (first_b && ans >= 0)
              first_b = false;
            else if (--ans < 0) {
              first_b = true;
              ans = -1;
            }
          }
          res = max(res, has_b ? ans : 0);
        }
      }
    }

    return res;
  }
};