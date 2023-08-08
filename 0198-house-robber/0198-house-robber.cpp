class Solution {
public:
  int rob(vector<int> &nums) {
    int n = (int)nums.size();

    int exc = 0, inc = 0;
    for (int i = 0; i < n; i++) {
      int new_inc = exc + nums[i];
      int new_exc = max(inc, exc);

      exc = new_exc;
      inc = new_inc;
    }

    return max(inc,exc);
  }
};