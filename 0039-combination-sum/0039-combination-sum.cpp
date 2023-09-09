class Solution {
public:
  void solve(int i, int sum, int target, vector<int> &arr, vector<int> &temp,
             vector<vector<int>> &ans) {

    if (i >= (arr.size()))
      return;

    if (sum == target) {
      ans.push_back(temp);
      return;
    }

    if (sum > target)
      return;

    temp.push_back(arr[i]);
    solve(i, sum + arr[i], target, arr, temp, ans);

    temp.pop_back();
    solve(i + 1, sum, target, arr, temp, ans);
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> temp;
    solve(0, 0, target, candidates, temp, ans);
    return ans;
  }
};