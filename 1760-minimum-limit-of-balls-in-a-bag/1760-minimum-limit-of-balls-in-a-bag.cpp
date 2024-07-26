class Solution {
public:
  int minimumSize(vector<int> &nums, int maxOperations) {
    int n = (int)nums.size();

    auto isOk = [&](int mid) {
      int ctr = 0;
      for (auto val : nums) {
        ctr += ((val - 1) / mid);
      }
      return ctr <= maxOperations;
    };

    int l = 1, r = INT_MAX, mid;
    int ans = INT_MAX;

    while (l <= r) {
      mid = l + (r - l) / 2;
      if (isOk(mid)) {
        ans = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }

    return ans;
  }
};
