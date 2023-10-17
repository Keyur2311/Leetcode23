//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution {
public:
  bool ok = false;
  void dfs(int src, int i, vector<int> adj[], vector<int> &vis,
           vector<vector<int>> &ans) {
    vis[src] = 1;
    ans[i][src] = 1;

    for (auto child : adj[src]) {
      if (vis[child])
        continue;
      dfs(child, i, adj, vis, ans);
    }
  }

  vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph) {
    vector<vector<int>> ans(N, vector<int>(N, 0));

    vector<int> adj[N];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (graph[i][j])
          adj[i].push_back(j);
      }
    }

    for (int i = 0; i < N; i++) {
      vector<int> vis(N, 0);
      dfs(i, i, adj, vis, ans);
    }

    return ans;
  }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}
// } Driver Code Ends