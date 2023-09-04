class Solution {
public:
  int findKthNumber(int m, int n, int k) {

    auto isOk = [&](int mid) {
      int ctr = 0;
      for (int i = 1; i <= m; i++)
        ctr += min(mid / i, n);

      return ctr >= k;
    };

    int l = 1, r = m * n, mid;
    while (l < r) {

      mid = l + (r - l) / 2;
      if (isOk(mid))
        r = mid;
      else
        l = mid + 1;
    }
    return r;
  }
};