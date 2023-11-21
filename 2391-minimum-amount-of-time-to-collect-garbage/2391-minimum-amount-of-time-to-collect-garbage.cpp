class Solution {
public:
  int garbageCollection(vector<string> &garbage, vector<int> &travel) {
    int n = (int)garbage.size();

    vector<vector<int>> pref(n, vector<int>(3, 0));
    vector<int> last(3, -1);

    vector<int> x(n - 1, 0);
    x[0] = travel[0];
    for (int i = 1; i < n - 1; i++)
      x[i] += travel[i] + x[i - 1];

    for (int i = 0; i < n; i++) {

      pref[i][0] = count(garbage[i].begin(), garbage[i].end(), 'M');
      pref[i][1] = count(garbage[i].begin(), garbage[i].end(), 'P');
      pref[i][2] = count(garbage[i].begin(), garbage[i].end(), 'G');

      if (pref[i][0] > 0)
        last[0] = i;
      if (pref[i][1] > 0)
        last[1] = i;
      if (pref[i][2] > 0)
        last[2] = i;

      if (i > 0) {
        pref[i][0] += pref[i - 1][0];
        pref[i][1] += pref[i - 1][1];
        pref[i][2] += pref[i - 1][2];
      }
    }

    int ans = 0;
    for (int i = 0; i < 3; i++) {
      if (last[i] != -1) {
        ans += pref[last[i]][i];
        if (last[i] >= 1)
          ans += x[last[i] - 1];
      }
    }

    return ans;
  }
};
