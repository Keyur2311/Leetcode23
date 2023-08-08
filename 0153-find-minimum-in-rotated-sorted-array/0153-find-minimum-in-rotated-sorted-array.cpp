class Solution {
public:
  int solve(int n, vector<int> &arr) {
    int l = 0, r = n - 1;
    int mid;
    while (l < r) {
      mid = l + (r - l) / 2;

      if (arr[mid] > arr[r])
        l = mid + 1;
      else
        r = mid;
    }
    return arr[l];
  }
  int findMin(vector<int> &nums) {
    int n = (int)nums.size();
    return solve(n, nums);
  }
};