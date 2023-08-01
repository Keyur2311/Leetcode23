class Solution {
public:
  void helper(int i, vector<int> &v, vector<int> &subset, vector<vector<int>> &ans) {

    if (i == (int)v.size()) {
      ans.push_back(subset);
        return;
    }
      
    subset.push_back(v[i]);
    helper(i + 1, v, subset, ans);

    subset.pop_back();
    helper(i + 1, v, subset, ans);
  }
    
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> subset;
    helper(0, nums, subset, ans);
    return ans;
  }
};