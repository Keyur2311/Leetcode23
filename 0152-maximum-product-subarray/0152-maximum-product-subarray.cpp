class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int n = (int)nums.size();
    int curr = 1, ans = INT_MIN;

    for (int i = 0; i < n; i++) {
      curr = curr * nums[i];
      ans = max(ans, curr);
      if (curr == 0)
        curr = 1;
    }
    curr = 1;
    for (int i = n - 1; i >= 0; i--) {
      curr = curr * nums[i];
      ans = max(ans, curr);
      if (curr == 0)
        curr = 1;
    }

    return ans;
  }
};