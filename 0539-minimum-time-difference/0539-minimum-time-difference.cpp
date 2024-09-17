
class Solution {
public:
  int findMinDifference(vector<string> &timePoints) {
    int n = (int)timePoints.size();

    vector<int> mins;
    for (auto &st : timePoints) {
      int min = (stoi(st.substr(0, 2)) * 60) + stoi(st.substr(3));
      mins.push_back(min);
    }

    sort(mins.begin(), mins.end());

    int ans = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
      ans = min(ans, mins[i + 1] - mins[i]);
      ans = min(ans, (1440 - mins[i + 1]) + mins[i]);
    }

    ans = min(ans, mins[n - 1] - mins[0]);
    ans = min(ans, (1440 - mins[n - 1]) + mins[0]);

    return ans;
  }
};