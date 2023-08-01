class Solution {
public:
  int splitArray(vector<int> &v, int m) {

    int n = (int)v.size();

    auto ok = [&](int mid, vector<int> &v, int m) {
      int ctr = 0;
      int sum = 0;
      for (int i = 0; i < n; i++) {
        if (v[i] > mid)
          return false;
        if (sum + v[i] > mid) {
          ctr++;
          sum = 0;
        }
        sum += v[i];
      }
      if (sum)
        ctr++;
      return ctr <= m;
    };

    int l = 0, r = 1e9;
    int mid, ans = r;

    while (l <= r) {
      mid = (l + r) / 2;
      if (ok(mid, v, m)) {
        ans = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    return ans;
  }
};