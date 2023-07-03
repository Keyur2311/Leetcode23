class Solution {
public:
  bool closeStrings(string word1, string word2) {
    map<int, int> mp1, mp2;

    for (auto &ch : word1)
      mp1[ch]++;
    for (auto &ch : word2)
      mp2[ch]++;

    vector<int> v1, v2;
    for (auto &it : mp1)
      v1.push_back(it.second);
    for (auto &it : mp2)
      v2.push_back(it.second);

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    if (v1 != v2)
      return false;

    for (char ch = 'a'; ch <= 'z'; ch++) {
      if (mp1[ch] != 0 && mp2[ch] != 0)
        continue;
      if (mp1[ch] == 0 && mp2[ch] == 0)
        continue;
      return false;
    }

    return true;
  }
};