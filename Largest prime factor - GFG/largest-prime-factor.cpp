//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

class Solution {
public:
  long long int largestPrimeFactor(int n) {
    long long int ans = 0;
    while (n % 2 == 0) {
      n = n / 2;
      ans = max(ans, 2LL);
    }

    for (int i = 3; i * i <= n; i = i + 2) {
      while (n % i == 0) {
        ans = max(ans, i*1LL);
        n = n / i;
      }
    }
    if (n > 2)
      ans = max(ans, n*1LL);
    return ans;
  }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends