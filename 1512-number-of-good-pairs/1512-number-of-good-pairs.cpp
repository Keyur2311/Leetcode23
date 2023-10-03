class Solution {
public:
  int numIdenticalPairs(vector<int> &nums) {
    int n = (int)nums.size();
    map<int, int> mp;
    for (auto it : nums)
      mp[it]++;

    int ans = 0;
    for (auto it : mp) {
      int fr = it.second;
      ans += ((fr * (fr - 1)) / 2);
    }

    return ans;
  }
};