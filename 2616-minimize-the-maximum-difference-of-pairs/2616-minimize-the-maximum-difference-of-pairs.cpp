class Solution {
public:
  int minimizeMax(vector<int> &nums, int p) {
    int n = (int)nums.size();
    if (n == 1)
      return 0;

    sort(nums.begin(), nums.end());

    auto isOk = [&](int mid) {
      int ctr = p;
      for (int i = 0; i < n - 1; i++) {
        if (nums[i + 1] - nums[i] <= mid) {
          ctr--;
          i++;
        }

        if (ctr == 0)
          break;
      }

      return ctr <= 0;
    };
      
    int l = 0, r = nums[n - 1] - nums[0];
    int mid;

    while (l < r) {
      mid = l + (r - l) / 2;

      if (isOk(mid)) {
        r = mid;
      } else
        l = mid + 1;
    }

    return r;
  }
};