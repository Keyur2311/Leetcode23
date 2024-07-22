class Solution {
public:
  vector<string> sortPeople(vector<string> &names, vector<int> &heights) {
    vector<pair<int, string>> vp;

    int n = (int)names.size();
    for (int i = 0; i < n; i++)
      vp.push_back({heights[i], names[i]});

    sort(vp.begin(), vp.end(), [](pair<int, string> &a, pair<int, string> &b) {
      return a.first > b.first;
    });

    vector<string> v;
    for (auto it : vp)
      v.push_back(it.second);

    return v;
  }
};