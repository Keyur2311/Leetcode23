class Solution {
public:
  void generatePermutations(int ind, vector<vector<int>> &ans,
                            vector<int> &nums) {
    if (ind == nums.size()) {
      ans.push_back(nums);
      return;
    }
    for (int i = ind; i < nums.size(); i++) {
      swap(nums[ind], nums[i]);
      generatePermutations(ind + 1, ans, nums);
      swap(nums[ind], nums[i]);
    }
  }

  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ans;
    generatePermutations(0, ans, nums);
    return ans;
  }
};