class Solution {
public:
  int maxAbsoluteSum(vector<int> &nums) {

    int ans = kadane(nums);
    for (auto &it : nums)
      it = -it;
    ans = max(ans, kadane(nums));
    return ans;
  }

  int kadane(vector<int> nums) {
    int totsum = nums[0];
    int currsum = nums[0];
    int n = nums.size();

    for (int i = 1; i < n; i++) {
      if (currsum >= 0)
        currsum += nums[i];
      else
        currsum = nums[i];

      if (abs(currsum) > totsum)
        totsum = currsum;
    }

    return totsum;
  }
};