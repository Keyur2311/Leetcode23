//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  string findLargest(int n, int sum) {
    if (n * 9 < sum || (n >= 2 && sum == 0))
      return to_string(-1);

    string ans = "";
    for (int i = 0; i < n; i++) {
      if (sum >= 9) {
        sum -= 9;
        ans.push_back((char)(9 + '0'));
      } else {
        ans.push_back((char)(sum + '0'));
        sum = 0;
      }
    }

    return ans;
  }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends