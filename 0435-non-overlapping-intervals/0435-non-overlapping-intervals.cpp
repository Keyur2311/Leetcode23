class Solution {
public:
  static bool cmp(const vector<int> &a, vector<int> &b) { return a[1] < b[1]; }

  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), cmp);

    int n = (int)intervals.size();
    int tot = 1, end = intervals[0][1];

    for (int i = 1; i < n; i++) {
      if (intervals[i][0] >= end) {
        tot++;
        end = intervals[i][1];
      }
    }

    return n - tot;
  }
};