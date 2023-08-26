class Solution {
public:
  int findLongestChain(vector<vector<int>> &pairs) {
    int n = (int)pairs.size();
    vector<int> lis(n, 1);
    sort(pairs.begin(), pairs.end());
    int mx = 1;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (pairs[j][1] < pairs[i][0] && lis[i] < lis[j] + 1) {
          lis[i] = lis[j] + 1;
        }
      }

      mx = max(mx, lis[i]);
    }

    return mx;
  }
};