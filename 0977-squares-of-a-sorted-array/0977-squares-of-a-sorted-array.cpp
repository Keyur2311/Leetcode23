class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    int n = (int)nums.size();

    int i = 0, j = n - 1, k = n - 1;
    vector<int> ans(n);

    while (i <= j) {
      if (abs(nums[i]) >= abs(nums[j])) {
        ans[k--] = nums[i] * nums[i];
        i++;
      } else {
        ans[k--] = nums[j] * nums[j];
        j--;
      }
    }

    return ans;
  }
};