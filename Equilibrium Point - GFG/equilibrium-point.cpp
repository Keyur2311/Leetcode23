//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
public:
  int equilibriumPoint(long long a[], int n) {
      
    if(n == 1) return 1;

   long long pref[n], suff[n];
    pref[0] = a[0], suff[n - 1] = a[n - 1];

    for (int i = 1; i < n; i++)
      pref[i] = (pref[i - 1] + a[i]);

    for (int i = n - 2; i >= 0; i--)
      suff[i] = (suff[i + 1] + a[i]);

    for (int i = 1; i < n - 1; i++) {
      if (pref[i - 1] == suff[i + 1])
        return i + 1;
    }
    return -1;
  }
};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends