class Solution {
public:
  int setBits(int n) {
    int ctr = 0;
    while (n) {
      ctr++;
      n = n & (n - 1LL);
    }
    return ctr;
  }

  vector<int> sortByBits(vector<int> &arr) {
    int n = (int)arr.size();
    vector<pair<int, int>> temp(n);

    for (int i = 0; i < n; i++)
      temp[i] = {setBits(arr[i]), arr[i]};

    sort(temp.begin(), temp.end());
    for (int i = 0; i < n; i++)
      arr[i] = temp[i].second;

    return arr;
  }
};