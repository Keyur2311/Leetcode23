class Solution {
public:
  long long int lcm(int a, int b) {
    return ((1LL * a * b) / (1LL * __gcd(a, b)));
  }

  vector<int> largestDivisibleSubset(vector<int> &nums) {
    int n = (int)nums.size();

    sort(nums.begin(), nums.end());

    vector<int> ans;

    vector<pair<int, int>> dp(n);

    for (int i = 0; i < n; i++) {
      dp[i].first = 1;
      dp[i].second = i;
    }

    int mx = 1, idx = 0;

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        long long int lc = lcm(nums[i], nums[j]);
        if (lc == nums[i] && dp[i].first < dp[j].first + 1) {
          dp[i].first = dp[j].first + 1;
          dp[i].second = j;
        }
      }
      if (dp[i].first > mx) {
        mx = dp[i].first;
        idx = i;
      }
    }
   
    while (idx != dp[idx].second) {
      ans.push_back(nums[idx]);
      idx = dp[idx].second;
    }
      
    ans.push_back(nums[idx]);

    sort(ans.begin(), ans.end());
    return ans;
  }
};