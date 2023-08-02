//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  bool isValid(int i, int j, int n, int m) {
    return i >= 0 && i <= n - 1 && j >= 0 && j <= m - 1;
  }
  bool compare(pair<int, pair<int, int>> &a,
                      pair<int, pair<int, int>> &b) {
    return a.first < b.first;
  }
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};

  int shortestDistance(int n, int m, vector<vector<int>> A, int x, int y) {

    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {0, 0}});

    vector<vector<int>> vis(n, vector<int>(m, 0));
    vis[0][0] = 1;
    int ans = 0;
    while (!pq.empty()) {
      ans++;

      int sz = pq.size();
      while (sz--) {
        auto curr = pq.top();
        pq.pop();

        int a = curr.second.first, b = curr.second.second;
        int dis = curr.first;
        if (a == x && b == y)
          return -dis;

        for (int i = 0; i < 4; i++) {
          int xx = a + dx[i];
          int yy = b + dy[i];
          if (isValid(xx, yy, n, m) && A[xx][yy] == 1 && !vis[xx][yy]) {
            vis[xx][yy] = 1;
            pq.push({dis - 1, {xx, yy}});
          }
        }
      }
    }

    return -1;
  }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends