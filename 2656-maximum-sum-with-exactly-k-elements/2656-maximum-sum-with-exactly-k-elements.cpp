class Solution {
public:
  int maximizeSum(vector<int> &nums, int k) {

    int ans = 0;
    int mx = 0;
    for (auto &it : nums)
      mx = max(mx, it);

    int n = mx + k - 1;
    int tot = (n * (n + 1)) / 2;
    int rn = mx - 1;
    int rtot = (rn * (rn + 1)) / 2;

    return tot - rtot;
  }
};