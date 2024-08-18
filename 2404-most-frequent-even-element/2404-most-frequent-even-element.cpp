class Solution {
public:
  int mostFrequentEven(vector<int> &nums) {
    map<int, int> mp;
    for (auto it : nums) {
      if (it & 1)
        continue;
      mp[it]++;
    }
    int fr = 0, ans = -1;

    for (auto it : mp) {
      if (it.second > fr) {
        fr = it.second;
        ans = it.first;
      }
    }
    return ans;
  }
};
