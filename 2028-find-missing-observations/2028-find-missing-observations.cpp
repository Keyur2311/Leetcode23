
class Solution {
public:
  vector<int> missingRolls(vector<int> &rolls, int mean, int n) {
    int m = (int)rolls.size();

    int msum = 0;
    for (auto &it : rolls)
      msum += it;

    int totsum = mean * (n + m);
    int nsum = totsum - msum;

    if (nsum > 6 * n || nsum <= 0 || nsum < n)
      return {};

    int avg = nsum / n;
    int rem = nsum % n;

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
      int x = avg;
      if (i <= rem)
        x += 1;
      ans.push_back(x);
    }
    return ans;
  }
};