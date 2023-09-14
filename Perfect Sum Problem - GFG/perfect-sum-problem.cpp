//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
  const int M = 1000000007;
  int perfectSum(int arr[], int n, int target) {
    int dp[n + 1][target + 1];

    for (int i = 1; i < target + 1; i++)
      dp[0][i] = 0;
    for (int i = 0; i < n + 1; i++)
      dp[i][0] = 1;

    for (int i = 1; i < n + 1; i++) {
      for (int j = 0; j < target + 1; j++) {
        if (arr[i - 1] <= j) {
          dp[i][j] = (dp[i - 1][j - arr[i - 1]] % M + dp[i - 1][j] % M) % M;
        } else {
          dp[i][j] = (dp[i - 1][j]) % M;
        }
      }
    }

    return (dp[n][target] % M);
  }
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends