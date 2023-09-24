class Solution {
public:
  long long maximumSumOfHeights(vector<int> &v) {
    int n = (int)v.size();

    stack<int> st;
    vector<int> prevsmall(n, -1);

    for (int i = 0; i < n; i++) {
      while (!st.empty() && v[st.top()] >= v[i])
        st.pop();

      if (!st.empty())
        prevsmall[i] = st.top();

      st.push(i);
    }

    vector<int> nextsmall(n, n);
    st = stack<int>();

    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && v[st.top()] >= v[i])
        st.pop();

      if (!st.empty())
        nextsmall[i] = st.top();

      st.push(i);
    }

    vector<long long> prefsum(n, 0);
    prefsum[0] = v[0];
    for (int i = 1; i < n; i++) {
      int prevSmallIdx = prevsmall[i];
      long long sameCount = i - prevSmallIdx;

      prefsum[i] += (1LL * sameCount * v[i]);
      prefsum[i] += (prevSmallIdx == -1 ? 0LL : prefsum[prevSmallIdx]);
    }

    vector<long long> suffsum(n, 0);
    suffsum[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      int nextSmallIdx = nextsmall[i];
      long long sameCount = nextSmallIdx - i;

      suffsum[i] += (1LL * sameCount * v[i]);
      suffsum[i] += (nextSmallIdx == n ? 0LL : suffsum[nextSmallIdx]);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
      ans = max(ans,  prefsum[i] + suffsum[i] - 1LL * v[i]);

    return ans;
  }
};
