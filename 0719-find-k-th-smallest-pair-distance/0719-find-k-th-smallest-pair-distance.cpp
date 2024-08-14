class Solution {
public:
  int findAns(vector<int> &nums, int max_diff) {
    int total = 0;
    int n = (int)nums.size();

    for (int i = 0; i < n; i++) {
      int l = i, r = n;
      int mid, idx = -1;
      while (r - l > 1) {
        int mid = l + (r - l) / 2;
        if (nums[mid] - nums[i] < max_diff) {
          l = mid;
        } else
          r = mid;
      }
      total += (l - i);
    }
    return total;
  }

  int smallestDistancePair(vector<int> &nums, int k) {
    int n = (int)nums.size();
    sort(nums.begin(), nums.end());

    int l = 0, r = nums.back() - nums[0] + 1;
    int mid, ans = -1;

    while (r - l > 1) {
      mid = l + (r - l) / 2;
      int curr = findAns(nums, mid);
      if (curr >= k)
        r = mid;
      else
        l = mid;
    }
    return l;
  }
};