class Solution {
public:
  const int M = 1000000007;

  int reverse(int number) {
    int remainder, rev = 0;
    while (number != 0) {
      remainder = number % 10;
      rev = rev * 10 + remainder;
      number /= 10;
    }
    return rev;
  }

  int countNicePairs(vector<int> &nums) {
    unordered_map<int, int> mp;

    int ans = 0;

    for (auto val : nums) {
      int x = val - reverse(val);
      ans = (ans % M + mp[x] % M) % M;
      mp[x]++;
    }

    ans %= M;
    return ans;
  }
};