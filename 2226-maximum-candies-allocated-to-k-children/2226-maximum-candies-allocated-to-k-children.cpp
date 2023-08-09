class Solution {
public:
  int maximumCandies(vector<int> &candies, long long k) {
    int n = (int)candies.size();

    auto isOk = [&](long long int mid) {
      long long int ctr = 0;
      for (int i = 0; i < n; i++) {
        ctr += ((1LL * candies[i]) / mid);
        if (ctr >= k)
          return true;
      }

      return false;
    };
    long long int l = 1, r = (long long int)1e15;
    long long int mid,ans=0;

    while (l <= r) {
      mid = l + (r - l) / 2;

      if (isOk(mid)) {
        l = mid + 1;
        ans = mid;
      } else
        r = mid - 1;
    }

    return ans;
  }
};