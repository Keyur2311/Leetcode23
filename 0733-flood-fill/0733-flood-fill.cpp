class Solution {
public:
  bool isValid(int i, int j, int n, int m) {
    return i >= 0 && i <= n - 1 && j >= 0 && j <= m - 1;
  }
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};

  void dfs(int i, int j, int ic, int nc, vector<vector<int>> &image) {
    int n = image.size();
    int m = image[0].size();

    image[i][j] = nc;
    for (int k = 0; k < 4; k++) {
      int x = i + dx[k];
      int y = j + dy[k];
      if (isValid(x, y, n, m) && image[x][y] == ic)
        dfs(x, y, ic, nc, image);
    }
  }
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int newColor) {
    if (image[sr][sc] != newColor)
      dfs(sr, sc, image[sr][sc], newColor, image);

    return image;
  }
};