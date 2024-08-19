class Solution {
public:
  int tupleSameProduct(vector<int> &nums) {
    int n = (int)nums.size();

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++)
        mp[nums[i] * nums[j]]++;
    }

    int ans = 0;
    for (auto [val, fr] : mp)
      ans += (((fr * (fr - 1)) / 2) * 8);

    return ans;
  }
};