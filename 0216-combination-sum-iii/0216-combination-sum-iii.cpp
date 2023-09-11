class Solution {
public:
  void solve(int idx, int target, int k, vector<int> &curr,
             vector<vector<int>> &result) {

    if (target == 0 && curr.size() == k) {
      result.push_back(curr);
      return;
    }

    if (idx > target || curr.size() > k || idx > 9)
      return;

    curr.push_back(idx);
    solve(idx + 1, target - idx, k, curr, result);

    curr.pop_back();
    solve(idx + 1, target, k, curr, result);
  }
  vector<vector<int>> combinationSum3(int k, int target) {
    vector<vector<int>> result;
    vector<int> curr;
    solve(1, target, k, curr, result);
    return result;
  }
};