class Solution {
public:
  vector<int> rearrangeArray(vector<int> &nums) {
    int n = (int)nums.size();
    vector<int> ans;

    int i = 0, j = 0;
    bool ok = true;

    while (ans.size() < n) {
      if (ok) {
        while (i < n && nums[i] <= 0)
          i++;
        ans.push_back(nums[i]);
        ok = !ok;
        i++;
      } else {
        while (j < n && nums[j] > 0)
          j++;
        ans.push_back(nums[j]);
        ok = !ok;
        j++;
      }
    }

    return ans;
  }
};