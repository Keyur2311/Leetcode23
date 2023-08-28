//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  bool isValid(int i, int j, int n, int m) {
    return i >= 0 && i <= n - 1 && j >= 0 && j <= m - 1;
  }
  int dx[8] = {0, 0, 1, -1, -1, 1, -1, 1};
  int dy[8] = {1, -1, 0, 0, 1, 1, -1, -1};

  int Count(vector<vector<int>> &matrix) {

    int n = (int)matrix.size();
    int m = (int)matrix[0].size();

    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == 0)
          continue;

        int ctr = 0;
        for (int k = 0; k < 8; k++) {
          int xx = i + dx[k];
          int yy = j + dy[k];
          if (isValid(xx, yy, n, m) && matrix[xx][yy] == 0)
            ctr++;
        }
        ans += (ctr > 0 && ctr % 2 == 0);
      }
    }

    return ans;
  }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends