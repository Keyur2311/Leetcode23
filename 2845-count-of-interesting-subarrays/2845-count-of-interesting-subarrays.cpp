class Solution {
public:
  long long countInterestingSubarrays(vector<int> &nums, int modulo, int k) {
    for (auto &val : nums) {
      if (val % modulo == k) {
        val = 1;
      } else
        val = 0;
    }

    unordered_map<int, int> count;
    count[0] = 1;
    long long pref = 0, ans = 0;

    for (auto val : nums) {
      pref = (pref + val) % modulo;
      ans += (count[(pref - k + modulo) % modulo]);
      count[pref]++;
    }
    return ans;
  }
};