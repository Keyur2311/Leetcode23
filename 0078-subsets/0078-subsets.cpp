// approach 1 : using recursion
// class Solution {
// public:
//   void solve(int idx, vector<int> &v, vector<int> &curr,
//              vector<vector<int>> &ans) {

//     ans.push_back(curr);

//     for (int i = idx; i < (int)v.size(); i++) {
//       curr.push_back(v[i]);
//       solve(i + 1, v, curr, ans);
//       curr.pop_back();
//     }
//   }

//   vector<vector<int>> subsets(vector<int> &nums) {
//     vector<vector<int>> ans;
//     vector<int> curr;
//     solve(0, nums, curr, ans);
//     return ans;
//   }
// };

//approach 2 : using sets
class Solution {
public:
  bool CheckBit(int n, int X) { return (bool)(n & (1 << X)); }

  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans;

    int n = (int)nums.size();
    int tot = 1 << n;

    for (int i = 0; i < tot; i++) {
      vector<int> curr;
      for (int j = 0; j < n; j++) {
        if (CheckBit(i, j))
          curr.push_back(nums[j]);
      }
      ans.push_back(curr);
    }

    return ans;
  }
};