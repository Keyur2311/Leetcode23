//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  vector<int> find(int arr[], int n, int x) {
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      v[i] = arr[i];

    vector<int> ans = {-1, -1};
    auto it1 = lower_bound(v.begin(), v.end(), x) - v.begin();
    if (it1 == n || v[it1]!=x) {
      return ans;
    }
    auto it2 = upper_bound(v.begin(), v.end(), x) - v.begin();
    it2--;

    ans = {it1, it2};
  }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends