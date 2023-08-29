class Solution {
public:
  int bestClosingTime(string customers) {

    int n = 0, y = 0;
    for (auto it : customers)
      y += (it == 'Y');

    int mn = y, hour = 0, ans = 0;
    for (auto it : customers) {
      n += (it == 'N');
      y -= (it == 'Y');
      hour++;
      
      if (y + n < mn) {
        mn = y + n;
        ans = hour;
      }
    }

    return ans;
  }
};