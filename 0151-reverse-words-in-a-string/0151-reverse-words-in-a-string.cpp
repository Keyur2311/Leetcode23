class Solution {
public:
  string reverseWords(string s) {
    int n = (int)s.size();

    int l = 0, r = n - 1;
    while (l < n && s[l] == ' ')
      l++;
    while (r >= 0 && s[r] == ' ')
      r--;

    string ans = "";
    int i = r;
    while (i >= l) {
      int ctr = 0;
      string temp = "";
      while (i >= l && s[i] != ' ')
        temp += s[i--];
      while (i >= l && s[i] == ' ')
        i--, ctr++;

      reverse(temp.begin(), temp.end());
      for (auto it : temp)
        ans += it;
      if (ctr > 0)
        ans += ' ';
    }
    return ans;
  }
};