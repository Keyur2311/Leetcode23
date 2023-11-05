class Solution {
public:
  int maximumBags(vector<int> &capacity, vector<int> &rocks,
                  int additionalRocks) {
    int n = (int)capacity.size();

    for (int i = 0; i < n; i++)
      capacity[i] = capacity[i] - rocks[i];

    sort(capacity.begin(), capacity.end());

    int ans = 0;
    int ctr = 0;

    for (int i = 0; i < n; i++) {
      int val = capacity[i];
      if (additionalRocks >= val) {
        additionalRocks -= val;
        ans++;
      } else
        break;
    }

    return ans;
  }
};