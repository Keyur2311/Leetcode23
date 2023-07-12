class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int totsum = nums[0];
    int currsum = nums[0];
    int n = nums.size();

    for (int i = 1; i < n; i++) {
      if (currsum >= 0)
        currsum += nums[i];
      else
        currsum = nums[i];

      if (currsum > totsum)
        totsum = currsum;
    }

    return totsum;
  }
};