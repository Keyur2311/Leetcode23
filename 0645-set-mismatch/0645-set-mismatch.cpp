
class Solution {
public:
  vector<int> findErrorNums(vector<int> &nums) {
    int n = (int)nums.size();
    map<int, int> mp;
    for (auto it : nums)
      mp[it]++;

    vector<int> ans(2);

    for (int i = 1; i <= n; i++) {
      if (!mp[i])
        ans[1] = i;
      if (mp[i] == 2)
        ans[0] = i;
    }
    return ans;
  }
};