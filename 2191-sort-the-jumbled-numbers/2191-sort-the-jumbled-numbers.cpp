class Solution {
public:
  vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums) {
    int m = 10;
    int n = (int)nums.size();

    vector<vector<int>> vp(n);
    for (int i = 0; i < n; i++)
      vp[i] = {-1, i, nums[i]};

    for (int i = 0; i < n; i++) {
      int temp = nums[i];
      int newNum = 0;
      string x = "";
      if (temp == 0)
        x = to_string(mapping[temp]);
      else {
        while (temp > 0) {
          int rem = temp % 10;
          x = to_string(mapping[rem]) + x;
          temp /= 10;
        }
      }
      newNum = stoi(x);
      vp[i][0] = newNum;
    }

    sort(vp.begin(), vp.end());

    vector<int> ans;
    for (auto it : vp)
      ans.push_back(it[2]);
    return ans;
  }
};