class Solution {
public:
  long long totalCost(vector<int> &costs, int k, int candidates) {
    int n = (int)costs.size();
    long long int ans = 0;
    int i = 0, j = (int)costs.size() - 1;

    priority_queue<int, vector<int>, greater<int>> pqf, pqb;

    while (k > 0) {

      while ((int)pqf.size() < candidates && i <= j)
        pqf.push(costs[i++]);
      while ((int)pqb.size() < candidates && i <= j)
        pqb.push(costs[j--]);

      int fval = (int)pqf.size() > 0 ? pqf.top() : INT_MAX;
      int bval = (int)pqb.size() > 0 ? pqb.top() : INT_MAX;

      if (fval <= bval) {
        ans += fval;
        pqf.pop();

      } else {
        ans += bval;
        pqb.pop();
      }
      k--;
    }

    return ans;
  }
};