class Solution {
public:
  int countConsistentStrings(string allowed, vector<string> &words) {
    int n = (int)words.size();
    set<char> st(allowed.begin(), allowed.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
      bool ok = true;
      for (int j = 0; j < (int)words[i].size(); j++) {
        if (!st.count(words[i][j])) {
          ok = false;
          break;
        }
      }
      if (ok)
        ans++;
    }

    return ans;
  }
};