
class StockSpanner {
public:
  stack<int> st;
  vector<int> v;
  int idx = -1;

  StockSpanner() {
    this->st = st;
    this->v = v;
    this->idx = idx;
  }

  int next(int price) {
    idx += 1;

    while (!st.empty() && v[st.top()] <= price)
      st.pop();

    int ans = idx + 1;
    if (!st.empty())
      ans = idx - st.top();

    st.push(idx);
    v.push_back(price);
    return ans;
  }
};