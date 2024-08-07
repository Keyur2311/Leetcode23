class Solution {
public:
  struct Compare {
    bool operator()(pair<int, int> const &a, pair<int, int> const &b) {
      if (a.first != b.first)
        return a.first > b.first;
      return a.second < b.second;
    }
  };
  int leastInterval(vector<char> &tasks, int n) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq1;
    map<char, int> mp;
    for (auto it : tasks)
      mp[it]++;

    for (auto it : mp)
      pq1.push({0, it.second});
      

    int ans = 0;
    while (!pq1.empty()) {
      auto curr = pq1.top();
      pq1.pop();

      int tm = curr.first;
      int fr = curr.second;
      
      int ctr = tm;
      fr--;
      ans += ctr + 1;
      priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq2;
      while (!pq1.empty()) {
        auto tp = pq1.top();
        pq1.pop();
        int tm1 = tp.first;
        int fr1 = tp.second;
        tm1 = max(tm1 - ctr - 1, 0);
        pq2.push({tm1, fr1});
      }

      if (fr > 0)
        pq2.push({n, fr});
      pq1 = pq2;
    }
    return ans;
  }
};