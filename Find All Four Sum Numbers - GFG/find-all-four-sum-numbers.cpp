//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &arr, int k) {
    int n = (int)arr.size();
    sort(arr.begin(), arr.end());

    set<vector<int>> st;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int target = k - arr[i] - arr[j];
        int l = j + 1, r = n - 1;
        while (l < r) {
          int sum = arr[l] + arr[r];
          if (sum == target) {
            st.insert({arr[i], arr[j], arr[l], arr[r]});
            l++, r--;
          } else if (sum < target)
            l++;
          else
            r--;
        }
      }
    }
    
    vector<vector<int>> ans(st.begin(),st.end());

    return ans;
  }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends