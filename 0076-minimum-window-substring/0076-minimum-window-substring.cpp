class Solution {
public:
  string minWindow(string s, string t) {
    int n = (int)s.size();
    int m = (int)t.size();

    unordered_map<char, int> mp;
    for (auto it : t)
      mp[it]++;

    int l = 0, r = 0, count = 0;
    int sIndex = -1, len = INT_MAX;

    while (r < n) {
      if (mp[s[r]] > 0)
        count++;
      mp[s[r]]--;

      while (count == m) {
        if (r - l + 1 < len) {
          len = r - l + 1;
          sIndex = l;
        }

        mp[s[l]]++;
        if (mp[s[l]] > 0)
          count--;
        l++;
      }
      r++;
    }
    return (sIndex == -1) ? "" : s.substr(sIndex, len);
  }
};