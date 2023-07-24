class Solution {
public:
  bool isPerfectSquare(int x) {
    for (long long int i = 1; i <= 100000; i++) {
      if (i * i * 1LL == 1LL * x)
        return true;
    }
    return false;
  }
};