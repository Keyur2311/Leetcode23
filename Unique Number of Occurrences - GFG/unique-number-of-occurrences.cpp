//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
public:
  bool isFrequencyUnique(int n, int arr[]) {
    unordered_map<int, int> m1;
    unordered_set<int> st;

    for (int i = 0; i < n; i++)
      m1[arr[i]]++;
    for (auto it : m1)
      st.insert(it.second);

    return (bool)(m1.size() == st.size());
  }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        bool ans=ob.isFrequencyUnique(n,arr);
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends