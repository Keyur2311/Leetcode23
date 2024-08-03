class Solution {
public:
  int countSeniors(vector<string> &details) {
    int n = (int)details.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
      int a = details[i][11] - '0';
      int b = details[i][12] - '0';
      int age = 0;
      if (a == 0)
        age = b;
      else {
        age = a;
        age *= 10;
        age += b;
      }
      ans += (age > 60);
    }
    return ans;
  }
};