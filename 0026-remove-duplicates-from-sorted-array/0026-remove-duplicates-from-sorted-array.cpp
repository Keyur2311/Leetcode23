class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int n = (int)nums.size();
    int idx = 1;
    for (int i = 1; i < n; i++) {
      if (nums[i - 1] != nums[i]) {
        nums[idx] = nums[i];
        idx++;
      }
    }
    return idx;
  }
};