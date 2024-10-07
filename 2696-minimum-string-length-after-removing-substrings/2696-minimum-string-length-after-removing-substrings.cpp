class Solution {
public:
  int minLength(string s) {
    int n = (int)s.size();

    stack<char> st;

    for (int i = 0; i < n; i++) {

      if (s[i] == 'B') {
        if (st.size() && st.top() == 'A')
          st.pop();
        else
          st.push(s[i]);
      } else if (s[i] == 'D') {
        if (st.size() && st.top() == 'C')
          st.pop();
        else
          st.push(s[i]);
      } else
        st.push(s[i]);
    }

    return st.size();
  }
};