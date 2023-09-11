class Solution {
public:
  void comsum(int idx, int target, int n, vector<int> &curr, vector<int> &arr,
              vector<vector<int>> &result) {
    if (target == 0) {
      result.push_back(curr);
      return;
    }

    for (int i = idx; i < n; i++) {
      if (i != idx && arr[i] == arr[i - 1])
        continue;
      if (arr[i] > target)
        break;
      curr.push_back(arr[i]);
      comsum(i + 1, target - arr[i], n, curr, arr, result);
      curr.pop_back();
    }
  }
  vector<vector<int>> combinationSum2(vector<int> &arr, int target) {
    vector<int> curr;
    int n = arr.size();
    vector<vector<int>> result;
    sort(arr.begin(), arr.end());
    comsum(0, target, n, curr, arr, result);
    return result;
  }
};