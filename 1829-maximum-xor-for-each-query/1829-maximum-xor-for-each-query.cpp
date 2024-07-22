class Solution {
public:
  int SetBit(int n, int X) { return n | (1LL << X); }
  bool CheckBit(int n, int X) { return (bool)(n & (1 << X)); }
  vector<int> getMaximumXor(vector<int> &nums, int maximumBit) {
    int n = (int)nums.size();

    vector<int> ans;

    int xr = 0;
    for (auto val : nums) {
      xr ^= val;
      int k = 0;
      for (int bit = 0; bit < maximumBit; bit++) {
        if (!CheckBit(xr, bit))
          k = SetBit(k, bit);
      }
      ans.push_back(k);
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};