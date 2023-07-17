class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int n = (int)matrix.size();
    int m = (int)matrix[0].size();

    int l = 0, r = n - 1;

    while (l <= r) {
      int mid = l + (r - l) / 2;
      int l1 = 0, r1 = m - 1;
      while (l1 <= r1) {
        int mid1 = l1 + (r1 - l1) / 2;
        if (matrix[mid][mid1] == target)
          return true;
        if (matrix[mid][mid1] > target)
          r1 = mid1 - 1;
        else
          l1 = mid1 + 1;
      }

      if (target < matrix[mid][0])
        r = mid - 1;
      else
        l = mid + 1;
    }

    return false;
  }
};
