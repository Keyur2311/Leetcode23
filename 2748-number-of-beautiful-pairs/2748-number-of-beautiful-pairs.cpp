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

    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (__gcd(nums[j] % 10, reverseNum(nums[i]) % 10) == 1)
          ans++;
      }
    }

    return ans;
  }
};