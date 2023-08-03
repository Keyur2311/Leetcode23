//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
  vector<int> shortestPath(int N, int M, vector<vector<int>> &edges) {
    vector<int> ans(N, INT_MAX);
    ans[0] = 0;

    for (int i = 0; i < M; i++) {
      if (edges[i][0] == 0) {
        ans[edges[i][1]] = edges[i][2];
      } else if (ans[edges[i][0]] != INT_MAX) {
        int temp = ans[edges[i][0]] + edges[i][2];
        ans[edges[i][1]] = min(temp, ans[edges[i][1]]);
      }
    }

    for (int i = 0; i < N; i++) {
      if (ans[i] == INT_MAX)
        ans[i] = -1;
    }
    return ans;
  }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends