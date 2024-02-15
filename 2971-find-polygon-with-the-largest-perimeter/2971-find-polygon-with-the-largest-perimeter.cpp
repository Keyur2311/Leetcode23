class Solution {
public:
  long long largestPerimeter(vector<int> &nums) {
    int n = (int)nums.size();
      
    sort(nums.begin(),nums.end());
      
    vector<long long> pref(n, 0);
    pref[0] = nums[0];

    for (int i = 1; i < n; i++)
      pref[i] += (1LL* pref[i - 1] + 1LL* nums[i]);

    long long ans = 0;
    for (int i = n - 1; i >= 2; i--) {
      if (pref[i - 1] > nums[i])
        ans = max(ans, 1LL * (1LL * nums[i] + 1LL * pref[i - 1]));
    }

    if (ans == 0)
      return -1;
     return ans;
  }
};