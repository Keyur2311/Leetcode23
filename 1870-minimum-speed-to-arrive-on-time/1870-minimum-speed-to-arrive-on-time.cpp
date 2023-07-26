class Solution {
public:
  int ceil_div(int a, int b) { return (a + b - 1) / b; }
  double ceil_div(double a, double b) { return (a + b - 1) / b; }
    
  int minSpeedOnTime(vector<int> &dist, double hour) {
    int n = (int)dist.size();

    auto ok = [&](int mid) {
      double ct = 0;
      for (int i = 0; i < n - 1; i++)
        ct +=(double)(ceil_div(dist[i], mid));
      
      double x = (double)dist[n-1];
      double y = (double)mid;
      ct+=(double)(x/y);
        
      return ct <= hour;
    };

    int l = 1, r = (int)1e7+5;
    int mid,ans = -1;

    while (l <= r) {
      mid = l + (r - l) / 2;
      if (ok(mid)) {
        ans = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }

  return ans;
  }
};