class Solution {
public:
  bool isQueenSafe(int row, int col, int n, vector<string> &board) {

    for (int i = row - 1, j = col; i >= 0; i--) {
      if (board[i][j] == 'Q')
        return false;
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
      if (board[i][j] == 'Q')
        return false;
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
      if (board[i][j] == 'Q')
        return false;
    }

    return true;
  }
  void getAns(int row, int n, vector<string> &board,
              vector<vector<string>> &ans) {
    if (row == n) {
      ans.push_back(board);
      return;
    }
    for (int col = 0; col < n; col++) {

      if (isQueenSafe(row, col, n, board)) {
        board[row][col] = 'Q';
        getAns(row + 1, n, board, ans);
        board[row][col] = '.';
      }
    }
  }
  vector<vector<string>> solveNQueens(int n) {

    vector<vector<string>> ans;
    string s(n, '.');
    vector<string> board(n, s);
    int row = 0;
    getAns(row, n, board, ans);
    return ans;
  }
};