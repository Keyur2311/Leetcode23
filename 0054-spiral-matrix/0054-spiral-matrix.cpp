class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int n = (int)matrix.size();
    int m = (int)matrix[0].size();

    int sr = 0, er = n - 1, sc = 0, ec = m - 1;
    vector<int> ans;

    while (sr <= er && sc <= ec) {
      int i = sr, j = sc;
      while (j <= ec)
        ans.push_back(matrix[i][j++]);
      sr += 1;

      i = sr, j = ec;
      while (i <= er)
        ans.push_back(matrix[i++][j]);
      ec -= 1;

      i = er, j = ec;

      if (sr <= er) {
        while (j >= sc)
          ans.push_back(matrix[i][j--]);
        er -= 1;
      }

      i = er, j = sc;
      if (sc <= ec) {
        while (sc <= ec && i >= sr)
          ans.push_back(matrix[i--][j]);
        sc += 1;
      }
    }

    return ans;
  }
};