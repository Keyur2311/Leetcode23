class Solution {
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int n = (int)nums.size();

    int i = 0, j = 0, ans = 0, prod = 1, len = 0;
    while (j < n) {

      prod *= nums[j++];

      while (i < j && prod >= k)
        prod /= nums[i++];
      ans += (j - i);
    }

    return ans;
  }
};