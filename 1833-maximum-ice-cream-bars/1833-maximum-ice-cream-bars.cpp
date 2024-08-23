
class Solution {
public:
  int maxIceCream(vector<int> &costs, int coins) {

    int n = (int)costs.size();

    vector<int> count((int)1e5 + 10, 0);

    for (auto val : costs)
      count[val]++;

    int i = 0, j = 0;

    while (i < n) {
      while (count[j] == 0)
        j++;
      costs[i] = j;
      count[j]--;
      i++;
    }

    int sum = 0, ans = 0;
    for (auto it : costs) {
      if (it > coins)
        break;
      ans++;
      coins-=it;
    }
    return ans;
  }
};