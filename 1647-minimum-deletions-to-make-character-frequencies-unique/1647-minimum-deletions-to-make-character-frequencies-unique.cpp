class Solution {
public:
  int minDeletions(string s) {
    int n = (int)s.size();
    map<char, int> mp;
    for (auto it : s)
      mp[it]++;

    int mx = INT_MIN;
    for (auto it : mp)
      mx = max(mx, it.second);

    set<int, greater<int>> st;
    for (int i = 1; i <= mx; i++)
      st.insert(i);

    vector<int> fr(mx + 1, 0);
    for (auto it : mp)
      fr[it.second] += 1;

    vector<int> v;
    for (int i = 1; i <= mx; i++) {
      while (fr[i]--)
        v.push_back(i);
    }

    sort(v.rbegin(), v.rend());
    int ans = 0;
    for (auto val : v) {
      auto it = st.lower_bound(val);
      if (it == st.end()) {
        ans += val;
        continue;
      }
      ans += (val - *it);
      st.erase(*it);
    }

    return ans;
  }
};
