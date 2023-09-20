class Solution {
public:
  int minOperations(vector<int> &nums, int x) {
    int n = (int)nums.size();

    vector<int> pref(n), suff(n);
    pref[0] = nums[0], suff[n - 1] = nums[n - 1];

    for (int i = 1; i < n; i++)
      pref[i] = (nums[i] + pref[i - 1]);
    for (int i = n - 2; i >= 0; i--)
      suff[i] = (nums[i] + suff[i + 1]);

    reverse(suff.begin(), suff.end());

    int ans = INT_MAX;
    for (int i = -1; i < n; i++) {
      int val = 0;
      if (i >= 0)
        val = pref[i];
      int target = x - val;
      auto it = lower_bound(suff.begin(), suff.end(), target) - suff.begin();
      if (it == n || target != suff[it] || (int)(i + it + 2) > n)
        continue;
      ans = min(ans, (int)(i + it + 2));
    }


    for (int i = -1; i < n; i++) {
      int val = 0;
      if (i >= 0)
        val = suff[i];
      int target = x - val;
      auto it = lower_bound(pref.begin(), pref.end(), target) - pref.begin();
      if (it == n || target != pref[it] || (int)(i + it + 2) > n)
        continue;
      ans = min(ans, (int)(i + it + 2));
    }

    if (ans == INT_MAX)
      ans = -1;

    return ans;
  }
};