class Solution {
public:
  int subarrayGCD(vector<int> &nums, int k) {
    int n = (int)nums.size();

    int ans = 0;
    for (int i = 0; i < n; i++) {
      int gc = 0;
      for (int j = i; j < n; j++) {
        gc = __gcd(gc, nums[j]);
        if (nums[j] % k)
          break;
        if (gc == k)
          ans++;
      }
    }
    return ans;
  }
};