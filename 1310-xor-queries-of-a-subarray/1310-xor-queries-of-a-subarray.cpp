class Solution {
public:
  vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
    int n = (int)arr.size();
    int m = (int)queries.size();

    vector<int> pref(n, 0);
    pref[0] = arr[0];

    vector<int> ans;

    for (int i = 1; i < n; i++)
      pref[i] = pref[i - 1] ^ arr[i];

    for (auto &query : queries) {
      int l = query[0];
      int r = query[1];

      int result = pref[r];
      if (l > 0)
        result ^= pref[l - 1];
      ans.push_back(result);
    }

    return ans;
  }
};