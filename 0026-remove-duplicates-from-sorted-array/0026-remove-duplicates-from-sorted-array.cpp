class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int n = (int)nums.size();
    int val = nums[0], idx = 0;
    for (int i = 1; i < n; i++) {
      if (nums[i - 1] != nums[i]) {
        nums[idx] = val;
        val = nums[i];
        idx++;
      }
    }
    
      nums[idx] = nums[n - 1];
      idx++;
    
    for (int i = idx; i < n; i++)
      nums[i] = 0;

    return idx;
  }
};