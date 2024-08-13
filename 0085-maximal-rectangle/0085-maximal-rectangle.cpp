
class Solution {
public:
  int maxInHistogram(vector<int> &arr) {
    int n = arr.size();
    int ans = 0;
    stack<int> st;

    for (int i = 0; i <= n; i++) {
      while (!st.empty() && (i == n || arr[st.top()] >= arr[i])) {
        int height = arr[st.top()];
        st.pop();
        int width;
        if (st.empty())
          width = i;
        else
          width = i - st.top() - 1;
        ans = max(ans, (height * width));
      }

      st.push(i);
    }
    return ans;
  }
  int maximalRectangle(vector<vector<char>> &mat) {
    int r = (int)mat.size();
    int c = (int)mat[0].size();

    int ans = 0;
    vector<int> h(c, 0);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (mat[i][j] == '1')
          h[j] += 1;
        else
          h[j] = 0;
      }

      ans = max(ans, maxInHistogram(h));
    }
    return ans;
  }
};