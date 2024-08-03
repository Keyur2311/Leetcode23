class Solution {
public:
  int search(vector<int> &arr, int target) {
    int n = (int)arr.size();

    int l = 0, r = n - 1, mid;

    while (l <= r) {
      mid = l + (r - l) / 2;
      if (arr[mid] == target)
        return mid;
      else if (arr[mid] < target)
        l = mid + 1;
      else
        r = mid - 1;
    }

    return -1;
  }
};