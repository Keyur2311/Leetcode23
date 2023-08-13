class Solution {
public:
  int minAbsoluteDifference(vector<int> &nums, int x) {
    int n = (int)nums.size();

    set<int> st;
    int diff = INT_MAX;
    for (int i = x; i < n; i++) {
      st.insert(nums[i - x]);
      auto it = st.lower_bound(nums[i]);
     
      if (it == st.end())
            it--;

      diff = min(diff, abs(*it - nums[i]));
      it--;
      if (it == st.end())
        continue;
      diff = min(diff, abs(*it - nums[i]));
    }

    return diff;
  }
};
