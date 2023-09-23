class Solution {
public:
  static bool comp(string &wordA, string &wordB) {
    return (int)wordA.size() < (int)wordB.size();
  }
    
  int longestStrChain(vector<string> &words) {
    sort(words.begin(), words.end(), comp);

    int n = (int)words.size();
    vector<int> dp(n, 1);

    auto isPredecessor = [&](string &a, string &b, int x, int y) {
      int ctr = 0, i = 0, j = 0;

      while (i < x && j < y) {
        if (a[i] == b[j]) {
          i++, j++;
          continue;
        } else {
          if (ctr >= 1)
            return false;
          ctr++;
          j++;
        }
      }

      if (ctr == 1 && i == x && j == y)
        return true;
      if (ctr == 0 && i == x && j == y - 1)
        return true;
      return false;
    };

    int ans = 1;
    for (int i = n - 2; i >= 0; i--) {
      for (int j = i + 1; j < n; j++) {
        int x = words[i].size(), y = words[j].size();
        if (x + 1 == y && isPredecessor(words[i], words[j], x, y)) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};