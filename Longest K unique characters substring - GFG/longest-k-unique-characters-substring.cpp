//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
  int longestKSubstr(string s, int k) {
    set<char> st(s.begin(), s.end());
    if (int(st.size()) < k)
      return -1;
    st.clear();

    int n = (int)s.size();
    int i = 0, j = 0;
    int ans = -1;
    map<char, int> mp;

    while (j < n) {
      while (st.size() <= k && j < n) {
        if (st.size() == k) {
          if (st.count(s[j])) {
            mp[s[j++]]++;
          } else
            break;
        } else if (st.size() < k) {
          mp[s[j]]++;
          st.insert(s[j++]);
        }
      }

      if (st.size() == k)
        ans = max(ans, j - i);

      while (i < j) {
        mp[s[i]]--;
        if (mp[s[i]] == 0) {
          st.erase(s[i]);
          break;
        }
        i++;
      }
      i++;
    }

    return ans;
  }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends