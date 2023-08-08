class Solution {
public:
  int numberOfRotations(int n, vector<int> &arr) {
    int l = 0, r = n - 1;
    int mid;
   while (l < r) {
      mid = l + (r - l) / 2;

      if (arr[mid] > arr[r])
        l = mid + 1;
      else
        r = mid;
    }
    return l;
  }

  int binarySearch(int lo, int hi, int n, int target, vector<int> arr) {
    int l = lo, r = hi;
    int mid;
    while (l <= r) {
      mid = l + (r - l) / 2;

      if (arr[mid] == target)
        return mid;

      if (arr[mid] > target)
        r = mid - 1;
      else
        l = mid + 1;
    }
    return -1;
  }
  int search(vector<int> &arr, int target) {
    int n = (int)arr.size();

    int idx = numberOfRotations(n, arr);

    int ans1 = binarySearch(0, idx - 1, n, target, arr);
    int ans2 = binarySearch(idx, n - 1, n, target, arr);
    cout<<idx<<endl;
    if (ans1 != -1)
      return ans1;
    if (ans2 != -1)
      return ans2;
    return -1;
  }
};