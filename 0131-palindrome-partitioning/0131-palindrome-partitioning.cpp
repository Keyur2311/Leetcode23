class Solution {
public:
  bool isPalindrome(const string &s, int start, int end) {
    while (start <= end) {
      if (s[start++] != s[end--])
        return false;
    }
    return true;
  }
  void solve(int index, string &s, vector<string> &path,
           vector<vector<string>> &ret) {
    if (index == s.size()) {
      ret.push_back(path);
      return;
    }
    for (int i = index; i < s.size(); ++i) {
      if (isPalindrome(s, index, i)) {
        path.push_back(s.substr(index, i - index + 1));
        solve(i + 1, s, path, ret);
        path.pop_back();
      }
    }
  }
  vector<vector<string>> partition(string s) {
    vector<vector<string>> ret;
    if (s.empty())
      return ret;

    vector<string> path;
    solve(0, s, path, ret);

    return ret;
  }
};