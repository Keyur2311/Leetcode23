//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
  bool CheckBit(int n, int X) { return (bool)(n & (1 << X)); }
  
  unsigned int getFirstSetBit(int n) {
    for (int i = 0; i <= 31; i++) {
      if (CheckBit(n, i))
        return i + 1;
    }
    return 0;
  }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin>>t; // testcases
    while(t--)
    {
        int n;
        cin>>n; //input n
        Solution ob;
        printf("%u\n", ob.getFirstSetBit(n)); // function to get answer
    }
	return 0;
}

// } Driver Code Ends