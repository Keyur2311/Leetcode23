class Solution {
public:
  bool buddyStrings(string s, string goal) {
    vector<int> v;
    for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] != goal[i])
        v.push_back(i);
    }

    if ((int)v.size() > 2 || (int)v.size() == 1)
      return false;

    if ((int)v.size() == 0) {
      map<char,int> mp;
      for (auto ch : s) {
        mp[ch]++;
        if (mp[ch] > 1)
          return true;
      }
      return false;
    }

    swap(s[v[0]], s[v[1]]);
    return (bool)(s == goal);
  }
};
