class Solution {
public:
  int maxPossibleScore(vector<int> &start, int d) {
    int n = (int)start.size();
    sort(start.begin(), start.end());

    auto isOk = [&](int mid) {
      long long int s = start[0];
      for (int i = 1; i < n; i++) {
        int val = start[i];
        s += mid;
        if (s < val)
          s = val;
        if (s > val + d)
          return false;
      }
    
      return true;
    };
    long long int l = 0, r = LLONG_MAX, mid, ans = -1;

    while (l <= r) {
      mid = l + (r - l) / 2;
      if (isOk(mid)) {
        ans = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }
    return ans;
  }
};