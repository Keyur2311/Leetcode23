class Solution {
public:
  bool CheckBit(int n, int X) { return (bool)(n & (1 << X)); }

  int maxLength(vector<string> &arr) {
    int n = (int)arr.size();

    int tot = 1 << n;
    int ans = 0;

    for (int i = 0; i < tot; i++) {
      unordered_set<char> st;
      bool ok = true;
      int sum = 0;

      for (int j = 0; j < n; j++) {
        if (CheckBit(i, j)) {
          sum += (int)arr[j].size();
          for (auto ch : arr[j]) {
            if (st.count(ch)) {
              ok = false;
              break;
            }
            st.insert(ch);
          }
        }
        if (!ok)
          break;
      }

      if (ok)
        ans = max(ans, sum);
    }

    return ans;
  }
};