class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {

    int sr = 0, er = n - 1, sc = 0, ec = n - 1;
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int val = 1;
    while (sr <= er && sc <= ec) {
      int i = sr, j = sc;
      while (j <= ec)
        ans[i][j++] = val++;
      sr += 1;

      i = sr, j = ec;
      while (i <= er)
        ans[i++][j] = val++;
      ec -= 1;

      i = er, j = ec;

      if (sr <= er) {
        while (j >= sc)
          ans[i][j--] = val++;
        er -= 1;
      }

      i = er, j = sc;
      if (sc <= ec) {
        while (sc <= ec && i >= sr)
          ans[i--][j] = val++;
        sc += 1;
      }
    }

    return ans;
  }
};