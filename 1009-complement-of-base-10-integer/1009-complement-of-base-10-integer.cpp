class Solution {
public:
  bool checkbit(int n, int x) { return (bool)(n & (1 << x)); }
  int toggle(int n, int x) { return n ^ (1 << x); }

  int bitwiseComplement(int num) {

    if (num == 0)
      return 1;

    bool ok = false;
    for (int i = 31; i >= 0; i--) {
      if (!ok && checkbit(num, i))
        ok = true;

      if (ok)
        num = toggle(num, i);
    }

    return num;
  }
};