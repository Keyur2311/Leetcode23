class Solution {
public:
  static bool cmp(const vector<int> &a, vector<int> &b) { return a[0] < b[0]; }

  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), cmp);

    int n = (int)intervals.size(), start = intervals[0][0],
        end = intervals[0][1];
    vector<vector<int>> ans;

    for (int i = 1; i < n; i++) {
      if(intervals[i][0]>=start && intervals[i][1]<=end) continue;
        
      if (intervals[i][0] <= end && intervals[i][1] > end) {
        end = intervals[i][1];
      } else {
        vector<int> temp = {start, end};
        ans.push_back(temp);
        start = intervals[i][0], end = intervals[i][1];
      }
    }
    vector<int> temp = {start, end};
    ans.push_back(temp);
    return ans;
  }
};