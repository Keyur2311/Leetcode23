class Solution {
public:
  int minOperations(vector<int> &nums) {
    int n = (int)nums.size();

    int ans = 0;
    for (int i = 1; i < n; i++) {
      int x = nums[i - 1] - nums[i] + 1;
      nums[i] = max(nums[i], nums[i] + x);
      ans += max(0, x);
    }

    return ans;
  }
};