//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  int setBits(int n) {
    int ctr = 0;
    while (n) {
      ctr++;
      n = n & (n - 1LL);
    }
    return ctr;
  }

  int is_bleak(int n) {
    for (int i = 0; i <= 31; i++) {
      int x = n - i;
      if (x < 0)
        continue;
      if (setBits(x) == i)
        return 0;
    }
    return 1;
  }
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends