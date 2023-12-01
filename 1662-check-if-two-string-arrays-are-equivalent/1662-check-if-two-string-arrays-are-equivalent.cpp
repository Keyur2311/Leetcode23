class Solution {
public:
  bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2) {
    int n = word1.size();
    int m = word2.size();

    string s1 = "", s2 = "";

    for (int i = 0; i < n; i++)
      s1 += word1[i];
    for (int i = 0; i < m; i++)
      s2 += word2[i];

    return s1 == s2;
  }
};