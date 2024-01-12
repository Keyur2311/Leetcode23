class Solution {
public:
  bool isvowel(char ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
  }
  int countVowels(string s) {
    int ctr = 0;
    for (auto ch : s) {
      if (isvowel(ch))
        ctr++;
    }
    return ctr;
  }
  bool halvesAreAlike(string s) {
    int n = (int)s.size();
    return (countVowels(s.substr(0, n / 2)) == countVowels(s.substr(n / 2)));
  }
};