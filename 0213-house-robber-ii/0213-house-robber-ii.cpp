class Solution {
public:
  int rob(vector<int> &nums) {
    int n = (int)nums.size();
      
    if(n==1) return nums[0];

    int exc = 0, inc = 0;
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      int new_inc = exc + nums[i];
      int new_exc = max(inc, exc);

      exc = new_exc;
      inc = new_inc;
    }

    ans = max(exc, inc);
    reverse(nums.begin(), nums.end());
    inc = 0, exc = 0;
    for (int i = 0; i < n - 1; i++) {
      int new_inc = exc + nums[i];
      int new_exc = max(inc, exc);

      exc = new_exc;
      inc = new_inc;
    }
    ans = max(ans, max(exc, inc));
    return ans;
  }
};