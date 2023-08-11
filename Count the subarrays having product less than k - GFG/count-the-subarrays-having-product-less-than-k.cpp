//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution {
public:
  long long countSubArrayProductLessThanK(const vector<int> &a, int n,
                                          long long k) {

    long long int i = 0, j = 0, ans = 0;
    long long int prod = 1;
    while (i <= j && j<n) {
      prod = prod * a[j];
      while (prod >= k && i < j) {
        prod = prod / a[i++];
      }
      if (prod < k)
        ans += (j - i + 1);
      j++;
    }

    return ans;
  }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends