class Solution {
public:
  int minOperations(string s) {
    int n = (int)s.size();

    string x(n, '0'), y(n, '1');

    for (int i = 1; i < n; i += 2)
      x[i] = '1';
    for (int i = 1; i < n; i += 2)
      y[i] = '0';

    int ans = n;
    int ctr1 = 0, ctr2 = 0;

    for (int i = 0; i < n; i++) {
      ctr1 += (x[i] != s[i]);
      ctr2 += (y[i] != s[i]);
    }

    ans = min(ctr1, ctr2);
    return ans;
  }
};