class Solution {
public:
  long long minimumReplacement(vector<int> &nums) {
    int n = (int)nums.size();
    long long ans = 0;
    int val = nums[n - 1];

    for (int i = n - 2; i >= 0; i--) {
      int totno = nums[i] / val;
      if ((nums[i] % val)) {
        totno++;
        val = nums[i] / totno;
      }
      ans += totno - 1;
    }
    return ans;
  }
};