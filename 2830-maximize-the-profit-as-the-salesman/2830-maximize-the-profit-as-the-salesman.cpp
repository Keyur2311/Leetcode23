class Solution {
public:
  class Job {
    public:
    int s, f, p;
  };

  static bool cmp(Job a, Job b) { return a.f < b.f; }

  int BinarySearch(vector<Job> &arr, int i) {
    int l = 0, r = i - 1;

    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (arr[mid].f < arr[i].s) {
        if (arr[mid + 1].f < arr[i].s)
          l = mid + 1;
        else
          return mid;
      } else
        r = mid - 1;
    }

    return -1;
  }
  int maximizeTheProfit(int n, vector<vector<int>> &offers) {

    n = (int)offers.size();
    vector<Job> arr(n);
    for (int i = 0; i < n; i++) {
      arr[i].s = offers[i][0];
      arr[i].f = offers[i][1];
      arr[i].p = offers[i][2];
    }

    sort(arr.begin(), arr.end(), cmp);
    vector<int> dp(n, 0);
    dp[0] = arr[0].p;

    for (int i = 1; i < n; i++) {
      int inc = 1LL * arr[i].p;
      int idx = BinarySearch(arr, i);
      if (idx != -1)
        inc += dp[idx];
      int exc = dp[i - 1];

      dp[i] = max(inc, exc);
    }

    return dp[n - 1];
  }
};