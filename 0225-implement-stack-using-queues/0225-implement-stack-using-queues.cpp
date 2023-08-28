class MyStack {
public:
  int tp = -1;
  queue<int> q1, q2;
  MyStack() {}

  void push(int x) {
    tp = x;
    q1.push(x);
  }

  int pop() {
    int sz = q1.size(), temp;

    if (sz == 1) {
      temp = q1.front();
      q1.pop();
      tp = -1;
      return temp;
    }

    int ts = sz - 1;
    while (ts--) {
      temp = q1.front();
      q1.pop();
      q2.push(temp);
      tp = temp;
    }

    temp = q1.front();
    q1.pop();
    q1 = q2;
    while (!q2.empty())
      q2.pop();

    return temp;
  }

  int top() { return tp; }

  bool empty() { return (bool)(q1.empty()); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */