class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &arr) {

    int n = (int)arr.size();
    vector<int> temp(n, -1), ans(n, 0);

    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && arr[st.top()] <= arr[i])
        st.pop();

      if (!st.empty())
        temp[i] = st.top();
      st.push(i);
    }

    for (int i = 0; i < n; i++) {
      if (temp[i] != -1)
        ans[i] = temp[i] - i;
    }

    return ans;
  }
};