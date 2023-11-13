class Solution {
public:
  bool isVowel(char ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
  }

  string sortVowels(string s) {
    int n = (int)s.size();

    string temp = "AEIOUaeiou";
    unordered_map<char, int> mp;
    for (auto ch : s)
      mp[ch]++;

    int i = 0;

    for (auto &ch : s) {
      if (isVowel(ch)) {
        while (!mp[temp[i]]) {
          i++;
        }
        ch = temp[i];
        mp[temp[i]]--;
      }
    }

    return s;
  }
};


// AEIOUaeiou