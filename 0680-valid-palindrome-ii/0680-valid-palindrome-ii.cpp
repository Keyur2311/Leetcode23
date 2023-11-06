class Solution {
public:
  bool validPalindrome(string s) {
    int n = (int)s.size();

    for (char ch = 'a'; ch <= 'z'; ch++) {
      int l = 0, r = n - 1;
      int ctr = 0;

      while (l < r) {
        if (s[l] == s[r]) {
          l++, r--;
          continue;
        } else if (s[l] == ch) {
          ctr++;
          l++;
        } else if (s[r] == ch) {
          ctr++;
          r--;
        } else {
          ctr++;
          l++;
        }
      }

      if (ctr <= 1)
        return true;
    }

    return false;
  }
};