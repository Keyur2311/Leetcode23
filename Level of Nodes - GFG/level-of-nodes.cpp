//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  int nodeLevel(int V, vector<int> adj[], int X) {
    vector<int> vis(V, 0);
    queue<pair<int, int>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
      auto tp = pq.front();
      pq.pop();
      int level = tp.first, node = tp.second;
      vis[node] = 1;

      if (node == X)
        return level;

      for (auto child : adj[node]) {
        if (vis[child])
          continue;
        pq.push({level + 1, child});
      }
    }

    return -1;
  }
};


//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends