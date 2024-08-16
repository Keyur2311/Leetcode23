class Solution {
public:
  bool isValid(int i, int j, int n, int m) {
    return i >= 0 && i <= n - 1 && j >= 0 && j <= m - 1;
  }
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};
  bool ok = false;
  bool solve(int i, int j, int n, int m, int count, string word,
             vector<vector<int>> &vis, vector<vector<char>> &board) {

    if (count == word.size())
      return true;

    for (int k = 0; k < 4; k++) {
      int x = i + dx[k];
      int y = j + dy[k];

      if (count < word.size() && isValid(x, y, n, m) &&
          word[count] == board[x][y] && !vis[x][y]) {
        vis[i][j] = 1;
        if(solve(x, y, n, m, count + 1, word, vis, board)) return true;
        vis[i][j] = 0;
      }
    }
      return false;
  }
  bool exist(vector<vector<char>> &board, string word) {
    int n = (int)board.size();
    int m = (int)board[0].size();

    if (word.size() > n * m)
      return false;

    int sz = (int)word.size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == word[0] && !vis[i][j]) {
          if (solve(i, j, n, m, 1, word, vis, board))
            return true;
        }
      }
    }
    return false;
  }
};