class Solution {
public:
  int minSteps(string s, string t) {
    int n = (int)s.size();
    map<int, int> mp1, mp2;

    for (auto ch : s)
      mp1[ch]++;

    for (auto ch : t)
      mp2[ch]++;

    int ans = 0;
    for (char ch = 'a'; ch <= 'z'; ch++) {
      if (mp1[ch] > mp2[ch])
        ans += (mp1[ch] - mp2[ch]);
    }

    return ans;
  }
};