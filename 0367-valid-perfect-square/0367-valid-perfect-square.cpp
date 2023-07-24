class Solution {
public:
  bool isPerfectSquare(int x) {
    long long int low = 1, hi = x;

    long long mid;

    while (low <= hi) {
      mid = low + (hi - low) / 2;
      long long int val = mid * mid * 1LL;
      if (val == x * 1LL)
        return true;
   
      if (val < x)
        low = mid + 1;
      else
        hi = mid - 1;
    }
    return false;
  }
};