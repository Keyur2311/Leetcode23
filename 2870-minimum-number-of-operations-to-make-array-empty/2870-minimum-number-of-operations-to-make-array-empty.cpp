class Solution {
public:
  int minOperations(vector<int> &nums) {
    int n = (int)nums.size();
    map<int, int> mp;
    for (auto it : nums)
      mp[it]++;

    int ans = 0;
    for (auto it : mp) {
      int fr = it.second;
      if (fr == 1)
        return -1;

      if (fr % 3 == 0)
        ans += (fr / 3);
      else if (fr % 3 == 2) {
        ans += (fr / 3);
        ans += 1;
      } else if (fr % 3 == 1) {
        int x = fr / 3;
        x -= 1;
        ans += x;
        fr -= x * 3;
        ans += 2;
      }
    }
    return ans;
  }
};
