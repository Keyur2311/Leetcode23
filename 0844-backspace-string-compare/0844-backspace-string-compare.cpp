class Solution {
public:
  string solve(string st) {
    int n = (int)st.size();
    int ctr = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (st[i] == '#')
        ctr++;
      else {
        if (ctr > 0) {
          st[i] = '*';
          ctr--;
          continue;
        }
      }
    }

    return st;
  }
  bool backspaceCompare(string s, string t) {
    string s1 = solve(s);
    string s2 = solve(t);
    int n = (int)s1.size(), m = (int)s2.size();

    int i = 0, j = 0;
    while (true) {

      while (i < n && (s1[i] == '*' || s1[i] == '#')) {
        i++;
        continue;
      }
      while (j < m && (s2[j] == '*' || s2[j] == '#')) {
        j++;
        continue;
      }

      if (i < n && j < m && s1[i] != s2[j])
        return false;

      if (i >= n || j >= m)
        break;
      i++, j++;
    }

    return (bool)(i == n && j == m);
  }
};
