class Solution {
public:
  int minLengthAfterRemovals(vector<int> &nums) {
    map<int, int> mp;
    for (auto it : nums)
      mp[it]++;
    priority_queue<int> pq;
    for (auto it : mp)
      pq.push(it.second);

    while (pq.size() > 1) {
      int a = pq.top();
      pq.pop();
      int b = pq.top();
      pq.pop();

      a--, b--;
      if (a != 0)
        pq.push(a);
      if (b != 0)
        pq.push(b);
    }

    if (pq.empty())
      return 0;
    return pq.top();
  }
};