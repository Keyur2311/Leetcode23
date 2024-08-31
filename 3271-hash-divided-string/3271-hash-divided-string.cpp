class Solution {
public:
  string stringHash(string s, int k) {

    int n = (int)s.size();
    int currsum = 0, ctr = 0;
    string ans;

    for (int i = 0; i < n; i++) {
      currsum += (int(s[i] - 'a'));
      ctr++;

      if (ctr == k) {
        ans.push_back((char)((currsum % 26) + 'a'));
        currsum = 0, ctr = 0;
      }
    }

    return ans;
  }
};