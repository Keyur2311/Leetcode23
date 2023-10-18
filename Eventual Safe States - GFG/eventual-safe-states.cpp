//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  bool DFS(int source, vector<bool> &visited, vector<bool> &currVisited,
           vector<int> adj[]) {
    visited[source] = true;
    currVisited[source] = true;

    for (auto child: adj[source]) {
      if (visited[child] == false) {
        if (DFS(child, visited, currVisited, adj)) {
          return true;
        }
      }

      else if (visited[child] == true && currVisited[child] == true)
        return true;
    }

    currVisited[source] = false;
    return false;
  }
  vector<int> eventualSafeNodes(int V, vector<int> adj[]) {

    vector<bool> visited(V, false);
    vector<bool> currVisited(V, false);

    for (int i = 0; i < V; i++) {
      if (visited[i] == false)
        DFS(i, visited, currVisited, adj);
    }

    vector<int> ans;
    for (int i = 0; i < V; i++) {
      if (!currVisited[i])
        ans.push_back(i);
    }

    return ans;
  }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends