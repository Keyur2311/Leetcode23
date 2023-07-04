class Solution {
public:
  bool CheckBit(int n, int X) { return (bool)(n & (1 << X)); }

  vector<int> singleNumber(vector<int> &nums) {
    int xr = 0, first = 0, second = 0, bit = 0;

    for (auto val : nums)
      xr ^= val;

    for (int i = 0; i < 32; i++) {
      if (CheckBit(xr, i)) {
        bit = i;
        break;
      }
    }

    for (auto val : nums) {
      if (CheckBit(val, bit))
        first ^= val;
      else
        second ^= val;
    }

    return {first, second};
  }
};