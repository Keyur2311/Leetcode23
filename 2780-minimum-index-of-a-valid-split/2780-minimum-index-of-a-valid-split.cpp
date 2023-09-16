class Solution {
public:
  int minimumIndex(vector<int> &nums) {
    int n = (int)nums.size();
    map<int, int> mp;
    int mx = 0;
    for (auto val : nums) {
      mp[val]++;
      mx = max(mx, mp[val]);
    }

    int c = -1;
    for (auto val : nums) {
      if (mp[val] == mx) {
        c = val;
        break;
      }
    }

    if (2 * mx <= n)
      return -1;

    int totfr = mx;
    int left = 0, right = totfr;

    for (int i = 0; i < n - 1; i++) {
      left += (nums[i] == c ? 1 : 0);
      right -= (nums[i] == c ? 1 : 0);

      int lt = i + 1, rt = n - lt;

      if (2 * left > lt && 2 * right > rt)
        return i;
    }

    return -1;
  }
};