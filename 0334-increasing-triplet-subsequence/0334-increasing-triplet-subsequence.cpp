// approach 1 : find LIS of nums. if LIS size is >=3 then ans is yes
// approach 2 : prefix array for min and suffix array for max
// approach 3:  use two variable min and max
class Solution {
public:
  bool increasingTriplet(vector<int> &nums) {
    int n = (int)nums.size();

    int a = INT_MAX, b = INT_MAX;

    for (int i = 0; i < n; i++) {
      if (nums[i] <= a)
        a = nums[i];
      else if (nums[i] <= b)
        b = nums[i];
      else if (nums[i] > a && nums[i] > b)
        return true;
    }
    return false;
  }
};