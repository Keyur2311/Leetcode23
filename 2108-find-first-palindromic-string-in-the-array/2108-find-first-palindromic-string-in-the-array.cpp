class Solution {
public:
  bool isPelindrome(string s) {
    string t = s;
    reverse(t.begin(), t.end());

    return t == s;
  }
  string firstPalindrome(vector<string> &words) {

    for (auto word : words) {
      if (isPelindrome(word))
        return word;
    }

    return "";
  }
};