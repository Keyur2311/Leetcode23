
class Solution {
public:
  int distributeCookies(vector<int> &cookies, int k) {

    int n = (int)cookies.size();
    sort(cookies.begin(), cookies.end());
    int totsum = 0;
    for (auto &it : cookies)
      totsum += it;

    auto ok = [&](int val) {
      int parts,sum;
      do {
        parts = 1, sum = 0;
        for (int i = 0; i < n; i++) {
          if (cookies[i] > val)
            return false;
          sum += cookies[i];
          if (sum > val) {
            sum = cookies[i];
            parts++;
          }
        }

        if (parts <= k)
          return true;
          
      } while (next_permutation(cookies.begin(), cookies.end()));

      return false;
    };

    int l = 0, r = totsum;
    int mid;
    while (l < r) {
      mid = l + (r - l) / 2;
      if (ok(mid))
        r = mid;
      else
        l = mid + 1;
    }

    return r;
  }
};