class Solution {
public:
  int chalkReplacer(vector<int> &chalk, int k) {
    int n = (int)chalk.size();

    long long int sum = 0;
    for (auto &it : chalk)
      sum += it;

    long long int x = k / sum;
    k -= (x * sum);

    for (int i = 0; i < n; i++) {
      if (k < chalk[i])
        return i;
      k -= chalk[i];
    }
    return -1;
  }
};