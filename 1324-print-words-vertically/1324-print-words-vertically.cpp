
class Solution {
public:
  vector<string> printVertically(string s) {
    int n = (int)s.size();
    vector<string> vp;

    string tp = "";
    for (auto c : s) {
      if (c == ' ') {
        vp.push_back(tp);
        tp = "";
      } else
        tp += c;
    }
    vp.push_back(tp);
    for (auto it : vp)
      cout << it << " ";

    int mx = 0;
    for (auto it : vp)
      mx = max(mx, (int)it.size());

    int sz = vp.size();

    vector<string> ans;

    for (int j = 0; j < mx; j++) {
      string tmp = "";
      for (int i = 0; i < sz; i++) {
        if (j < vp[i].size())
          tmp += vp[i][j];
        else
          tmp += ' ';
      }

      int k = (int)tmp.size();
      int z = k - 1;
      int idx = z;
      while (z >= 0) {
        if (tmp[z] == ' ')
          z--;
        else {
          idx = z - 1;
          break;
        }
      }

      string u = "";
      for (int i = 0; i <= z; i++)
        u += tmp[i];

      if (u == "")
        break;
      ans.push_back(u);
    }
    return ans;
  }
};