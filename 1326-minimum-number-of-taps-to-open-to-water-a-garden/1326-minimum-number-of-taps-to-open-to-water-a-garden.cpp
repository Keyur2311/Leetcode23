class Solution {
public:
  static bool cmp(const vector<int> &a, vector<int> &b) { 
      if(a[0]!=b[0])
      return a[0] < b[0];
      return a[1]<b[1];
  }

  int merge(vector<vector<int>> &vp) {
    sort(vp.begin(), vp.end(), cmp);
// for (int i = 0; i < vp.size(); i++)
//     cout << vp[i][0] << " " << vp[i][1] << endl;
    int n = (int)vp.size(), start = vp[0][0], end = vp[0][1];
    int i = 1;
    

    while (i < n && vp[i][0] == start) {
      end = vp[i][1];
      i++;
    }

    int ctr = 1;

    if (start == 0 && end == n - 1)
      return 1;
    int mx = -1;
    while (i < n) {
      int st = i;
      while (i < n && vp[i][0] <= end) {
        mx = max(mx, vp[i][1]);
        i++;
      }
        
      if(st==i && end!=n-1) return -1;
        
      end = mx;
      ctr++;
       if(start==0 && end==n-1)
        return ctr;
    }
    
    if(end==n-1)
    return ctr;
      
    return -1;
  }

  int minTaps(int n, vector<int> &ranges) {

    vector<vector<int>> vp(n + 1, vector<int>(2));
    for (int i = 0; i < n + 1; i++) {
      vp[i][0] = max(0, i - ranges[i]);
      vp[i][1] = min(n, i + ranges[i]);
    }
    // for (int i = 0; i < vp.size(); i++)
    // cout << vp[i][0] << " " << vp[i][1] << endl;

    return merge(vp);
  }
};
    

// 9
// [0,5,0,3,3,3,1,4,0,4]