class Solution {
public:
  int minCapability(vector<int> &nums, int k) {
    int n = (int)nums.size();
    if (n == 1)
      return nums[0];

    auto isOk = [&](int mid) {
      int ctr = k;
      for (int i = 0; i < n; i++) {
        if (nums[i] <= mid) {
          ctr--;
          i++;
        }

        if (ctr == 0)
          break;
      }

      return ctr <= 0;
    };
    int l = 1, r = (int)1e9;
    int mid;

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