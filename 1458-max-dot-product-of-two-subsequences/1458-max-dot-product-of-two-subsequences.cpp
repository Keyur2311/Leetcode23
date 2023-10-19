class Solution {
public:
  int maxDotProduct(vector<int> &nums1, vector<int> &nums2) {
    int n = (int)nums1.size(), m = (int)nums2.size();

    int mx = INT_MIN;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    bool ok = false;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int val = nums1[i - 1] * nums2[j - 1];
        dp[i][j] = max({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1],
                        val + dp[i - 1][j - 1]});
        mx = max(mx, dp[i][j]);

        if (nums1[i - 1] == 0 || nums2[j - 1] == 0)
          ok = true;
      }
    }

    if (ok || mx!=0)
      return mx;

    mx = INT_MIN;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        mx = max(mx, nums1[i] * nums2[j]);
    }
    return mx;
  }
};

// // 
// [-5,3,-5,-3,1]
// [-2,4,2,5,-5]