class Solution {
public:
  int minSizeSubarray(vector<int> &nums, int target) {
    vector<int> v = nums;
    long long arr_sum = 0;

    int toadd = 0;
    for (auto i : v) 
      arr_sum += i;
    
    if (arr_sum < target) {
      toadd += v.size() * (target / arr_sum);
      target %= arr_sum;
    }

    for (auto i : v) 
      nums.push_back(i);
    
    int n = nums.size();
    int i = 0, j = 0;
    long long sum = 0;
    int ans = 1e9 + 7;
    while (j < n) {
      sum += nums[j];
      if (sum > target) {
        while (i < n && sum > target) {
          sum -= nums[i];
          i++;
        }
      }
      if (sum == target) 
        ans = min(ans, j - i + 1);
     
      j++;
    }
    ans = ans + toadd;
    return ans >= 1e6 ? -1 : ans;
  }
};