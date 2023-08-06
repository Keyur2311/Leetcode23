//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  void generatePermutations(int ind, vector<string> &ans, string &s) {
    if (ind == s.size()) {
      ans.push_back(s);
      return;
    }
    for (int i = ind; i < s.size(); i++) {
      swap(s[ind], s[i]);
      generatePermutations(ind + 1, ans, s);
      swap(s[ind], s[i]);
    }
  }

  vector<string> permutation(string S) {
    vector<string> ans;
    generatePermutations(0, ans, S);
    sort(ans.begin(),ans.end());
    return ans;
  }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends