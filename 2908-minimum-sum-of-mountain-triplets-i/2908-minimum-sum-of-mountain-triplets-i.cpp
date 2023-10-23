class Solution {
public:
  int minimumSum(vector<int> &nums) {
    int n = (int)nums.size();

    vector<int> pref(n), suff(n);
    pref[0] = nums[0], suff[n - 1] = nums[n - 1];
    for (int i = 1; i < n; i++)
      pref[i] = min(pref[i - 1], nums[i]);

    for (int i = n - 2; i >= 0; i--)
      suff[i] = min(suff[i + 1], nums[i]);

    int ans = INT_MAX;
    for (int i = 1; i < n - 1; i++) {
      if (pref[i - 1] < nums[i] && nums[i] > suff[i + 1])
        ans = min(ans, pref[i - 1] + nums[i] + suff[i + 1]);
    }

    return (ans != INT_MAX ? ans : -1);
  }
};