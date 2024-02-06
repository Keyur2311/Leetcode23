class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    int n = (int)strs.size();

    vector<vector<string>> ans;

    vector<pair<string, string>> p;

    for (auto str : strs)
      p.push_back({str, str});

    for (int i = 0; i < n; i++)
      sort(p[i].first.begin(), p[i].first.end());

    sort(p.begin(), p.end());

    vector<string> temp;
    temp.push_back(p[0].second);

    for (int i = 1; i < n; i++) {
      if (p[i - 1].first == p[i].first)
        temp.push_back(p[i].second);
      else {
        ans.push_back(temp);
        temp = {};
        temp.push_back(p[i].second);
      }
    }

    ans.push_back(temp);
    return ans;
  }
};