class Solution {
public:
  int maxCoins(vector<int> &piles) {
    int n = (int)piles.size();

    sort(piles.rbegin(), piles.rend());
    int ans = 0;
    for (int i = 1; i < n - n / 3; i += 2)
      ans += piles[i];

    return ans;
  }
};
