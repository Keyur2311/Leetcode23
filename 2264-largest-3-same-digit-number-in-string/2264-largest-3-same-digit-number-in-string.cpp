class Solution {
public:
  string largestGoodInteger(string num) {
    int dig = -1;
    int n = (int)num.size();
    for (int i = 0; i <= n - 3; i++) {
      int currd = (int)(num[i] - '0');
      if (num[i] == num[i + 1] && num[i + 1] == num[i + 2] && currd > dig)
        dig = currd;
    }

    string ans = "";
    if (dig != -1) {
      char chdig = (char)(dig + '0');
      string s(3, chdig);
      ans = s;
    }

    return ans;
  }
};