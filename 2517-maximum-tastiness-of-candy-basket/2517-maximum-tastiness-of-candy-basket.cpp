class Solution {
public:
  bool check(int mid, vector<int> &price, int k) {
    int n = (int)price.size();
    int count = 1;
    int prev = price[0];
    for (int i = 1; i < n; i++) {
      if (price[i] - prev < mid)
        continue;
      count++;
      prev = price[i];
    }

    if (count < k)
      return false;
    return true;
  }

  int maximumTastiness(vector<int> &price, int k) {
    int n = price.size();
    sort(price.begin(), price.end());

    int l = 0, r = price.back();
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (check(mid, price, k))
        l = mid;
      else
        r = mid - 1;
    }
    return l;
  }
};