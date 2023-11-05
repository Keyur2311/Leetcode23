class Solution {
public:
  static bool cmp(const vector<int> &a, vector<int> &b) { return a[1] > b[1]; }

  int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), cmp);

    int ans = 0, ctr = 0;
    int n = (int)boxTypes.size();

    for (int i = 0; i < n; i++) {
      int fr = boxTypes[i][0], units = boxTypes[i][1];

      int take = min(truckSize, fr);
      truckSize -= take;

      ans += take * units;
    }

    return ans;
  }
};