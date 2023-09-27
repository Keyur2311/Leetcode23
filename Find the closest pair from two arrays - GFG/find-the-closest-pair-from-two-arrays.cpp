//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution {
public:
  vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
    int i = 0, j = m - 1;
    int mn = INT_MAX;
    vector<int> ans = {-1, -1};
    while (i < n && j >= 0) {
      int sum = arr[i] + brr[j];
      int df = abs(x - sum);

      if (df < mn) {
        mn = df;
        ans = {arr[i], brr[j]};
      }

      if (sum < x)
        i++;
      else
        j--;
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends