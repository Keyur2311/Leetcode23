class Solution {
public:
  long long makeSubKSumEqual(vector<int> &arr, int k) {
    int n = (int)arr.size();
    int gc = __gcd(n, k);

    vector<int> v[gc];
    for (int i = 0; i < n; i++)
      v[i % gc].push_back(arr[i]);

    long long ans = 0;

    for (int i = 0; i < gc; i++) {

      sort(v[i].begin(), v[i].end());
      long long ctr = 0, median = 0;

      int sz = (int)v[i].size();
      if (sz & 1)
        median = v[i][sz / 2];
      else
        median = (v[i][(sz / 2) - 1] + v[i][sz / 2]) / 2;

      for (auto val : v[i])
        ctr += abs(median - val);

      ans += ctr;
    }

    return ans;
  }
};