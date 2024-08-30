class Solution {
public:
  int minStoneSum(vector<int> &piles, int k) {
    int n = (int)piles.size();

    priority_queue<int> pq;
    for (auto it : piles)
      pq.push(it);
    int ans = 0;
    while (!pq.empty() && k > 0) {
      auto curr = pq.top();
      pq.pop();

      int x = curr / 2;
      int y = curr - x;
      k--;
      if (y > 0)
        pq.push(y);
    }
    while(!pq.empty()){
        ans+=pq.top();
        pq.pop();
    }
    return ans;
  }
};