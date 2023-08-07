class Solution {
public:
  int singleNonDuplicate(vector<int> &nums) {
    int n = (int)nums.size();
    if (n == 1)
      return nums[0];

    int lo = 0, hi = n - 1;
    int mid;
    while (lo <= hi) {
      mid = lo + (hi - lo) / 2;

      if (mid - 1 >= 0 || mid + 1 < n) {
        if (mid - 1 >= 0 && nums[mid - 1] == nums[mid]) {
          int left = mid - 1, right = n - mid - 1;
          if (left & 1)
            hi = mid - 2;
          else
            lo = mid + 1;
        } else if (mid + 1 < n && nums[mid] == nums[mid + 1]) {
          int left = mid, right = n - mid - 2;
          if (left & 1)
            hi = mid - 1;
          else
            lo = mid + 2;
        } else
          return nums[mid];
      }
    }
    return nums[lo];
  }
};