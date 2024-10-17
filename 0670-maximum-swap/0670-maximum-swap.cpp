class Solution {
public:
  int maximumSwap(int num) {
    string s = to_string(num);
    int n = (int)s.size();

    int ans = num;

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        string temp = s;
        swap(temp[i], temp[j]);
        ans = max(ans, stoi(temp));
      }
    }

    return ans;
  }
};