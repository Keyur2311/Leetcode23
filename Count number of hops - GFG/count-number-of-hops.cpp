//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  const int M = 1000000007;
  long long countWays(int n) {

    if (n <= 2)
      return n;

    long long ans = 1;
    vector<long long> dp(n + 1, 0);
    dp[0] = 1, dp[1] = 1, dp[2] = 2;
    
    for (int i = 3; i <= n; i++)
      dp[i] = (dp[i - 1] % M + dp[i - 2] % M + dp[i - 3] % M) % M;

    return (dp[n] % M);
  }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends