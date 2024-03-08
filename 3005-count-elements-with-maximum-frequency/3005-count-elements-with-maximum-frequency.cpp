class Solution {
public:
  int maxFrequencyElements(vector<int> &nums) {

    int mx = 0;

    map<int, int> mp;
    for (auto it : nums) {
      mp[it]++;
      mx = max(mx, mp[it]);
    }

    int ans = 0;
    for (auto it : mp) {
      if (it.second == mx)
        ans += it.second;
    }

    return ans;
  }
};