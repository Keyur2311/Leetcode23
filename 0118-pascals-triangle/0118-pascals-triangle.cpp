class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;

    for (int i = 1; i <= numRows; i++) {
      vector<int> v;
      if (i == 1)
        v.push_back(1);
      else {
        for (int k = 0; k < i; k++) {
          if (k == 0)
            v.push_back(1);
          else if (k == i - 1)
            v.push_back(1);
          else {
            int idx = i - 2;
            v.push_back(ans[idx][k - 1] + ans[idx][k]);
          }
        }
      }
      ans.push_back(v);
    }

    return ans;
  }
};