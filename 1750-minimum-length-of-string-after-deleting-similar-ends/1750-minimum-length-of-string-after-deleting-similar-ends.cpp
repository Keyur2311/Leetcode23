class Solution {
public:
  int minimumLength(string s) {
    int n = (int)s.size();

    int i = 0, j = n - 1;
    int ans = n;

    while (i < j) {
      if (s[i] == s[j]) {
        while (i + 1 < j && s[i] == s[i + 1])
          i++;

        while (j - 1 > i && s[j - 1] == s[j])
          j--;
          
        i++,j--;
      } else
        break;
    }

    ans = (j - i + 1);

    return ans;
  }
};