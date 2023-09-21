//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends

class Solution {
public:
  int FindMaxSum(int arr[], int n) {
    int exc = 0, inc = 0;
    for (int i = 0; i < n; i++) {
      int new_inc = exc + arr[i];
      int new_exc = max(inc, exc);

      exc = new_exc;
      inc = new_inc;
    }

    return max(inc, exc);
  }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends