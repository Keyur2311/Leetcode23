class Solution {
public:
  string smallestSubsequence(string s) {
    stack<char> st;
    map<char, int> mp;
    for (auto ch : s)
      mp[ch]++;

    map<char, int> vis;

    for (auto ch : s) {
      while (!st.empty() && vis[ch] == false && ch < st.top() &&
             mp[st.top()] > 0) {
        vis[st.top()] = false;
        st.pop();
      }

      if (!vis[ch]) {
        st.push(ch);
        vis[ch] = true;
      }
      mp[ch]--;
    }

    string ans;
    while (!st.empty()) {
      ans.push_back(st.top());
      st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};