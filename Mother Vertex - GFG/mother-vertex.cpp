//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  void dfs(int src, vector<int> &vis, vector<int> adj[]) {

    vis[src] = 1;
    for (auto child : adj[src]) {
      if (vis[child])
        continue;
      dfs(child, vis, adj);
    }
  }

  int findMotherVertex(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    int mother = -1;
    for (int i = 0; i < V; i++) {
      if (!vis[i]) {
        dfs(i, vis, adj);
        mother = i;
      }
    }
   
     for (int i = 0; i < V; i++)
          vis[i] = 0;

    dfs(mother, vis, adj);
    for (int i = 0; i < V; i++) {
      if (!vis[i])
        return -1;
    }
    return mother;
  }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends