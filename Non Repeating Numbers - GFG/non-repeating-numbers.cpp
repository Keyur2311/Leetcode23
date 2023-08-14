//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  bool CheckBit(int n, int X) { return (bool)(n & (1 << X)); }

  vector<int> singleNumber(vector<int> nums) {
    int xr = 0, first = 0, second = 0, bit = 0;

    for (auto val : nums)
      xr ^= val;

    for (int i = 0; i < 32; i++) {
      if (CheckBit(xr, i)) {
        bit = i;
        break;
      }
    }

    for (auto val : nums) {
      if (CheckBit(val, bit))
        first ^= val;
      else
        second ^= val;
    }
    
    if(first > second) swap(first,second);

    return {first, second};
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
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends