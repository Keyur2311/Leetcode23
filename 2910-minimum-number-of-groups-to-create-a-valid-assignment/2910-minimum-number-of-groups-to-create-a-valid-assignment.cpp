class Solution {
public:
  int ceil_div(int a, int b) { return (a + b - 1) / b; }

  int minGroupsForValidAssignment(vector<int> &nums) {
    int n = (int)nums.size();
    unordered_map<int, int> mp;

    for (auto it : nums)
      mp[it]++;

    int g = INT_MAX;
    for (auto it : mp)
      g = min(g, it.second);

    auto split = [&](int g1) {
      int groups = 0, g = g1 - 1;
      for (auto it : mp) {
        int c = it.second;
        int group_cnt = c / g1, last_group = c % g1;
        if (last_group && last_group + group_cnt < g)
          return INT_MAX;
        groups += group_cnt + (last_group > 0);
      }
      return groups;
    };

    for (int i = g + 1; i >= 1; i--) {
      int x = split(i);
      if (x != INT_MAX)
        return x;
    }
    return 1;
  }
};