class MedianFinder {
public:
  priority_queue<int> left;
  priority_queue<int, vector<int>, greater<int>> right;
  MedianFinder() {}
  
  void addNum(int num) {
    if (left.empty()) {
      left.push(num);
      return;
    }
    int size1 = left.size();
    int size2 = right.size();
    if (size1 == size2) {
      int tmp = right.top();
      if (num <= tmp) {
        left.push(num);
      } else {
        left.push(tmp);
        right.pop();
        right.push(num);
      }
    } else {
      int tmp = left.top();
      if (tmp <= num) {
        right.push(num);
      } else {
        left.pop();
        left.push(num);
        right.push(tmp);
      }
    }
  }

  double findMedian() {
    int size1 = left.size();
    int size2 = right.size();
    if (size1 > size2) {
      return left.top();
    } else {
      return (left.top() + right.top()) / 2.0;
    }
  }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */