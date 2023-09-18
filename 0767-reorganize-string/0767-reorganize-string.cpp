class Solution {
public:
  string reorganizeString(string s) {
    int n = (int)s.size();

    if (n == 1)
      return s;

    map<char, int> mp;
    for (auto ch : s)
      mp[ch]++;

    priority_queue<pair<int, char>> pq;
    for (auto it : mp)
      pq.push({it.second, it.first});
    string ans;
    while (pq.size() > 1) {
      auto a = pq.top();
      pq.pop();
      auto b = pq.top();
      pq.pop();

      ans.push_back(a.second);
      ans.push_back(b.second);
      a.first--, b.first--;

      if (a.first)
        pq.push({a.first, a.second});
      if (b.first)
        pq.push({b.first, b.second});
    }

    if (pq.empty())
      return ans;
    auto tp = pq.top();
    pq.pop();
    if (tp.first == 1 && ans.size() > 0 && tp.second != ans.back()) {
      ans.push_back(tp.second);
      return ans;
    }
    return "";
  }
};