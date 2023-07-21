class Solution {
public:
  int findNumberOfLIS(vector<int> &arr) {
    int n = arr.size();
    int lis[n], count[n];
    lis[0] = 1;
    count[0] = 1;

    int mx = 1;
    for (int i = 1; i < n; i++) {
      lis[i] = 1;
      count[i] = 1;
      for (int j = 0; j < i; j++) {
        if (arr[i] > arr[j]) {
          if (lis[j] + 1 > lis[i]) {
            lis[i] = lis[j] + 1;
            count[i] = count[j];
          } else if (lis[j] + 1 == lis[i])
            count[i] += count[j];
        }
      }
      mx = max(mx, lis[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (lis[i] == mx)
        ans += count[i];
    }
    return ans;
  }
};