class Solution {
public:
  int findJudge(int n, vector<vector<int>> &trust) {
    int ans = -1;

    for (int i = 1; i <= n; i++) {
      int tg = 0;
      int tk = 0;
      for (int j = 0; j < trust.size(); j++) {

        int u = trust[j][0];
        int v = trust[j][1];
        if (v == i)
          tg++;
        if (u == i) {
          tk++;
          break;
        }
      }
      if (tk == 0 && tg == n - 1) {
        ans = i;
        break;
      }
    }
    return ans;
  }
};