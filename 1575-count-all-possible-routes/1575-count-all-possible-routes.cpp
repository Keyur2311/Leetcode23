
class Solution {
public:
  int M = 1000000007;
  int solve(vector<int> &locations, int start, int fuel, int finish,
            vector<vector<int>> &dp) {

    if (fuel < 0)
      return 0;

    if (dp[start][fuel] != -1)
      return dp[start][fuel];

    int ans = 0;
    if (start == finish)
      ans++;

    for (int i = 0; i < (int)locations.size(); i++) {
      if (i != start && abs(locations[start] - locations[i])) {
        ans += solve(locations, i, fuel - abs(locations[start] - locations[i]),
                     finish, dp) % M;
        ans %= M;
      }
    }
    return dp[start][fuel] = ans % M;
  }
    
  int countRoutes(vector<int> &locations, int start, int finish, int fuel) {

    int n = (int)locations.size();
    vector<vector<int>> dp(n, vector<int>(fuel + 1, -1));
    int ans = solve(locations, start, fuel, finish, dp);
    return ans;
  }
};