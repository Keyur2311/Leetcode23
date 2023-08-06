class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int n = (int)nums.size();

    int idx1, idx2;
    for (idx1 = n - 2; idx1 >= 0; idx1--) {
      if (nums[idx1] < nums[idx1 + 1])
        break;
    }

    if (idx1 < 0)
      reverse(nums.begin(), nums.end());
    else {
      for (idx2 = n - 1; idx2 > idx1; idx2--) {
        if (nums[idx2] > nums[idx1])
          break;
      }
      swap(nums[idx1], nums[idx2]);
      reverse(nums.begin() + idx1 + 1, nums.end());
    }
  }
};
