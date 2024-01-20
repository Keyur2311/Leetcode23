class Solution {
public:
  vector<vector<int>> findMatrix(vector<int> &nums) {
    vector<vector<int>> ans;
    map<int, int> mp;

    int mx = 0;
    for (auto it : nums) {
      mp[it]++;
      mx = max(mx, mp[it]);
    }

    while (mx--) {
      vector<int> v;
      for (int i = 1; i <= 200; i++) {
        if (mp[i] >= 1) {
          v.push_back(i);
          mp[i]--;
        }
      }
      ans.push_back(v);
    }

    return ans;
  }
};