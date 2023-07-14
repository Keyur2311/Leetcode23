class Solution {
public:
  int longestSubsequence(vector<int> &arr, int difference) {
    int n = (int)arr.size();

    unordered_map<int, int> mp;
    int mx = 1;

    for (int i = 0; i < n; i++) {
      mp[arr[i]] = max(mp[arr[i]], mp[arr[i] - difference] + 1);
      mx = max(mx, mp[arr[i]]);
    }
    return mx;
  }
};