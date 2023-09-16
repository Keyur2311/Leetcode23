class Solution {
public:
  string minimumString(string a, string b, string c) {
    vector<string> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

    vector<int> p = {0, 1, 2};

    vector<string> temp;

    do {
      a = v[p[0]], b = v[p[1]], c = v[p[2]];
      int lena = (int)a.size(), lenb = (int)b.size(), lenc = (int)c.size();

      string ta = a, tb = b, tc = c;
      reverse(ta.begin(), ta.end());
      int idx = -1;
      for (int i = 0; i < min(lena, lenb); i++) {
        string t1 = ta.substr(0, i + 1), t2 = tb.substr(0, i + 1);
        reverse(t1.begin(), t1.end());
        if (t1 == t2) {
          idx = i;
        }
      }

      if (a.find(b) == string::npos) {
        for (int i = idx + 1; i < lenb; i++)
          a.push_back(b[i]);
      }

      ta = a, tc = c;
      reverse(ta.begin(), ta.end());
      idx = -1;
      lena = (int)a.size();
      for (int i = 0; i < min(lena, lenc); i++) {
        string t1 = ta.substr(0, i + 1), t2 = tc.substr(0, i + 1);
        reverse(t1.begin(), t1.end());
        if (t1 == t2) {
          idx = i;
        }
      }
      
      if (a.find(c) == string::npos) {
        for (int i = idx + 1; i < lenc; i++)
          a.push_back(c[i]);
      }

      temp.push_back(a);

    } while (next_permutation(p.begin(), p.end()));

    int mn = INT_MAX;
    for (auto it : temp)
      mn = min(mn, (int)it.size());

    vector<string> ans;
    for (auto it : temp) {
      if ((int)it.size() == mn)
        ans.push_back(it);
    }

    sort(ans.begin(), ans.end());
    return ans[0];
  }
};