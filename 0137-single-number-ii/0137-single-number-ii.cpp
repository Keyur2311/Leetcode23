class Solution {
public:
  bool CheckBit(int n, int X) { return (bool)(n & (1 << X)); }
  int SetBit(int n, int X) { return n | (1LL << X); }

  int singleNumber(vector<int> &nums) {
    int ans = 0;

    for (int i = 0; i < 32; ++i) {
      int sum = 0;
      for (auto num : nums) {
        if (CheckBit(num, i))
          sum += 1;
      }
      sum %= 3;
      if (sum)
        ans = SetBit(ans, i);
    }

    return ans;
  }
};