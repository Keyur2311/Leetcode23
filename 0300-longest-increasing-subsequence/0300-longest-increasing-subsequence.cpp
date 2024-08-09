class Solution {
public:
  int lowerBound(int target, vector<int> &ans) {
    int n = (int)ans.size();
    int l = 0, r = n - 1, mid, idx = -1;

    while (l <= r) {
      mid = l + (r - l) / 2;
      if (ans[mid] >= target) {
        idx = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    return idx;
  }
  int lengthOfLIS(vector<int> &arr) {
    int n = (int)arr.size();

    vector<int> ans;
    ans.push_back(arr[0]);

    for (int i = 1; i < n; i++) {
      int idx = lowerBound(arr[i], ans);
      if (idx < ans.size())
        ans[idx] = arr[i];
      else 
        ans.push_back(arr[i]);
    }

    return (int)ans.size();
  }
};