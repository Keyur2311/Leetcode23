//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int minimumMultiplications(vector<int> &arr, int start, int end) {

    
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, start});
    vector<int> vis(100005,0);
    vis[start] = 1;
    int ctr = 100000;
    while ((int)(pq.size()) > 0 && ctr--) {
      auto tp = pq.top();
      pq.pop();

      if (tp.second == end)
        return tp.first;

      for (auto it : arr){
        int val = (tp.second * it) % 100000;
        if(vis[val]) continue;
        pq.push({tp.first + 1, val});
        vis[val]=1;
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends