class Solution {
public:
  void solve(int idx, vector<int> &v, vector<int> &curr,
             vector<vector<int>> &ans) {

    ans.push_back(curr);

    for (int i = idx; i < (int)v.size(); i++) {
      curr.push_back(v[i]);
      solve(i + 1, v, curr, ans);
      curr.pop_back();
    }
  }

  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> curr;
    solve(0, nums, curr, ans);
    return ans;
  }
};