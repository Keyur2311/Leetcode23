class Solution {
private:
  vector<int> nextSmallerOnRight(vector<int> &heights, int n) {
    stack<int> st;
    vector<int> v(n, n);

    st.push(n - 1);
    for (int i = n - 2; i >= 0; i--) {
      while (!st.empty() && heights[st.top()] >= heights[i])
        st.pop();

      if (!st.empty())
        v[i] = st.top();
      st.push(i);
    }
    return v;
  }

  vector<int> prevSmallerOnLeft(vector<int> &heights, int n) {
    stack<int> st;
    vector<int> v(n, -1);

    st.push(0);
    for (int i = 1; i < n; i++) {
      while (!st.empty() && heights[st.top()] >= heights[i])
        st.pop();

      if (!st.empty())
        v[i] = st.top();
      st.push(i);
    }
    return v;
  }

public:
  int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();

    vector<int> nxt = nextSmallerOnRight(heights, n);
    vector<int> prv = prevSmallerOnLeft(heights, n);

    int maxArea = INT_MIN;

    for (int i = 0; i < n; i++) {
      int w = nxt[i] - prv[i] - 1;
      int area = w * heights[i];
      maxArea = max(maxArea, area);
    }
    return maxArea;
  }
};