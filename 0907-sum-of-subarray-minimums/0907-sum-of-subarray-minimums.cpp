class Solution {
public:
  const long long int M = 1000000007;
  int mod_add(long long int a, long long int b, long long int m) {
    a = a % m;
    b = b % m;
    return ((((a % m) + (b % m)) % m) + m) % m;
  }
  int mod_mul(long long int a, long long int b, long long int m) {
    a = a % m;
    b = b % m;
    return (((a % m) * (b % m) % m) + m) % m;
  }

  // PSE = PREVIOUS SMALLEST ELEMENT
  vector<int> PSE(vector<int> &arr) {
    int n = (int)arr.size();

    stack<int> st;
    vector<int> v(n, -1);
    st.push(0);

    for (int i = 1; i < n; i++) {
      while (!st.empty() && arr[st.top()] >= arr[i])
        st.pop();

      if (!st.empty())
        v[i] = st.top();

      st.push(i);
    }

    return v;
  }

  // NSE = NEXT SMALLEST ELEMENT
  vector<int> NSE(vector<int> &arr) {

    int n = (int)arr.size();

    stack<int> st;
    vector<int> v(n, n);

    st.push(n - 1);

    for (int i = n - 2; i >= 0; i--) {
      while (!st.empty() && arr[st.top()] > arr[i])
        st.pop();

      if (!st.empty())
        v[i] = st.top();

      st.push(i);
    }

    return v;
  }

  int sumSubarrayMins(vector<int> &arr) {

    int n = (int)arr.size();
    vector<int> l = PSE(arr);
    vector<int> r = NSE(arr);

    int ans = 0;

    for (int i = 0; i < n; i++) {
      long long int totleft = i - l[i];
      long long int totright = r[i] - i;

      int ctr = mod_mul(totleft, totright, M);

      int tot = mod_mul(ctr, arr[i], M);
      ans = mod_add(ans, tot, M);
    }

    return ans;
  }
};