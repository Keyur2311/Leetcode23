class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    int row[9][9], col[9][9], sqr[9][9];
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        row[i][j] = 0;
        col[i][j] = 0;
        sqr[i][j] = 0;
      }
    }

    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.')
          continue;
        int val = (board[i][j] - '0') - 1;
        int k =  (i / 3) * 3 + j / 3;
        if (row[i][val] || col[j][val] || sqr[k][val])
          return false;
        row[i][val] = 1, col[j][val] = 1, sqr[k][val] = 1;
      }
    }

    return true;
  }
};