class Solution {
public:
  int minDays(int n) {

    if (n == 1)
      return 1;

    queue<int> q;
    q.push(n);

    set<int> st;
    int ans = 0;

    while (!q.empty()) {
      ans++;

      int sz = q.size();
      while (sz--) {
        int tp = q.front();
        q.pop();

        if (tp == 0)
          return ans - 1;
        if (st.count(tp))
          continue;

        st.insert(tp);

        q.push(tp - 1);
        if (tp % 2 == 0)
          q.push(tp / 2);
        if (tp % 3 == 0)
          q.push(tp / 3);
      }
    }

    return ans;
  }
};