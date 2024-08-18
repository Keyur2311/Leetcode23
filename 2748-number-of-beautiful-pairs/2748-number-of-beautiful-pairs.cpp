class Solution {
public:
  int reverseNum(int n) {
    int rev = 0;

    while (n != 0) {
      int d = n % 10;
      rev = rev * 10 + d;
      n /= 10;
    }

    return rev;
  }
  int countBeautifulPairs(vector<int> &nums) {
    int n = (int)nums.size();

    map<int, int> frc, lsc;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int fr = reverseNum(nums[i]) % 10;
      int ls = nums[i] % 10;

      for (auto it : frc) {
        int a = it.first;
        int b = ls;
        ans += (__gcd(a, b) == 1 ? it.second : 0);
      }
      frc[fr]++;
      lsc[ls]++;
    }

    return ans;
  }
};