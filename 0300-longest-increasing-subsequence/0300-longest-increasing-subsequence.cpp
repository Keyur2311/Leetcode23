class Solution {
public:
  int lengthOfLIS(vector<int> &arr) {
    int n = (int)arr.size();

    vector<int> lis(n, 1);
    int mx = 1;

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (arr[i] > arr[j] && lis[j] + 1 > lis[i])
          lis[i] = lis[j] + 1;
      }
      mx = max(mx, lis[i]);
    }
    return mx;
  }
};