//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  static bool isValid(int i, int j, int n, int m) {
    return i >= 0 && i <= n - 1 && j >= 0 && j <= m - 1;
  }
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};

  void dfs(int i, int j, int n, int m, vector<vector<int>> &vis,
           vector<vector<char>> &mat) {

    vis[i][j] = -1;
    for (int a = 0; a < 4; a++) {
      int xx = i + dx[a];
      int yy = j + dy[a];
      if (isValid(xx, yy, n, m) && mat[xx][yy] == 'O' && vis[xx][yy] == 0)
        dfs(xx, yy, n, m, vis, mat);
    }
  }
  vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) &&
            mat[i][j] == 'O' && vis[i][j] == 0) {
          dfs(i, j, n, m, vis, mat);
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (vis[i][j] == -1)
          continue;
        mat[i][j] = 'X';
      }
    }
    return mat;
  }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends