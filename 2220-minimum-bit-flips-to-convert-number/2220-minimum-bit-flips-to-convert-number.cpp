class Solution {
public:
  bool CheckBit(int n, int X) { return (bool)(n & (1 << X)); }

  int minBitFlips(int start, int goal) {
    int ctr = 0;

    for (int bit = 0; bit < 32; bit++) {
      if (CheckBit(start, bit) && !CheckBit(goal, bit))
        ctr++;
      else if (!CheckBit(start, bit) && CheckBit(goal, bit))
        ctr++;
    }

    return ctr;
  }
};