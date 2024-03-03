class Solution {
public:
  string maximumOddBinaryNumber(string s) {

    int n = (int)s.size();
    int ones = 0;
    for (auto ch : s) {
      if (ch == '1')
        ones++;
    }

    if (ones == 0) {
      return s;
    } else if (ones == 1) {
      for (int i = 0; i < n - 1; i++)
        s[i] = '0';
      s[n - 1] = '1';
      return s;
    }
    s[n - 1] = '1';
    ones--;

    int i = 0;
    while (i < n - 1 && ones--) {
      s[i] = '1';
      i++;
    }
    while (i < n - 1){
      s[i] = '0';
      i++;
    }
    return s;
  }
};