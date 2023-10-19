class Solution {
public:
  string solve(string st) {
    int n = (int)st.size();
    int ctr = 0;
    string t = "";
    for (int i = n - 1; i >= 0; i--) {
      if (st[i] == '#')
        ctr++;
      else {
        if (ctr > 0) {
          ctr--;
          continue;
        } else
          t.push_back(st[i]);
      }
    }

    reverse(t.begin(), t.end());
    return t;
  }
  bool backspaceCompare(string s, string t) {
    string s1 = solve(s);
    string s2 = solve(t);

    return (bool)(s1 == s2);
  }
};