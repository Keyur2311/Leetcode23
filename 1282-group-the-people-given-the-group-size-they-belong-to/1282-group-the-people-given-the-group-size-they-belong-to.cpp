class Solution {
public:
  vector<vector<int>> groupThePeople(vector<int> &groupSizes) {
    vector<vector<int>> ans;
    int n = (int)groupSizes.size();
    vector<int> v[n + 1];
    for (int i = 0; i < n; i++)
      v[groupSizes[i]].push_back(i);

    for (int i = 1; i <= n; i++) {
      vector<int> temp;
      int ctr = 0;
      for (int j = 0; j < (int)v[i].size(); j++) {
        temp.push_back(v[i][j]);
        ctr++;
        if (ctr == i) {
          ctr = 0;
          ans.push_back(temp);
          temp.clear();
        }
      }
    }

    return ans;
  }
};