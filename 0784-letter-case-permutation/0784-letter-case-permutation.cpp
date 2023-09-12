class Solution {
public:
  bool isDigit(char ch) { return ch >= '0' && ch <= '9'; }
  void solve(int idx, int n, string &s, string &curr, vector<string> &ans) {

    if (idx >= n) {
      ans.push_back(curr);
      return;
    }

    if (isDigit(s[idx])) {
      curr.push_back(s[idx]);
      solve(idx + 1, n, s, curr, ans);
      curr.pop_back();
    } else {
        
      char lo = tolower(s[idx]);
      curr.push_back(lo);
      solve(idx + 1, n, s, curr, ans);
      curr.pop_back();

      char up = toupper(s[idx]);
      curr.push_back(up);
      solve(idx + 1, n, s, curr, ans);
      curr.pop_back();
    }
  }
  vector<string> letterCasePermutation(string s) {
    int n = (int)s.size();
    vector<string> ans;
    string curr;
    solve(0, n, s, curr, ans);
    return ans;
  }
};
