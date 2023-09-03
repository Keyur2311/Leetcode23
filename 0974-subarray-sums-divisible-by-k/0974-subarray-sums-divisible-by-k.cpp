class Solution {
public:
  int subarraysDivByK(vector<int> &nums, int k) {
    vector<int> count(k);
    count[0] = 1;
    int pref = 0, ans = 0;

    for (auto val : nums) {
      pref = (pref + val % k + k) % k;
      ans += (count[pref]++);
    }
    return ans;
  }
};
