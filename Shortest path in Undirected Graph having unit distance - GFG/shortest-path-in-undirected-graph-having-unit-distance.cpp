//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
  vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src) {

    vector<pair<int, int>> g[N];
    for (int i = 0; i < M; i++) {
      g[edges[i][0]].push_back({edges[i][1], 1});
      g[edges[i][1]].push_back({edges[i][0], 1});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    pq.push({0, src});

    vector<int> dis(N, INT_MAX);
    dis[src] = 0;

    while (!pq.empty()) {
      auto p = pq.top();
      pq.pop();
      int curr = p.second;

      for (auto it : g[curr]) {
        if (dis[curr] + it.second < dis[it.first]) {
          dis[it.first] = dis[curr] + it.second;
          pq.push({dis[it.first], it.first});
        }
      }
    }

   for (auto &it : dis)
      it = (it == INT_MAX ? -1 : it);


    return dis;
  }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends