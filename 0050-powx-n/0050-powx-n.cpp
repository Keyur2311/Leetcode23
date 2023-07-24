class Solution {
public:
  double myPow(double x, int n) {

    if (n < 0)
      x = 1 / x;

    double pow = 1;
    long long int num = labs(n);

    while (num) {
      if (num & 1) {
        pow *= x;
      }
      x *= x;
      num >>= 1;
    }

    return pow;
  }
};