class Solution {
public:
  vector<int> getRow(int r) {
    int n = r + 1;
    vector<int> v(n);
    v[0] = v[r] = 1;
    long long num = r, dino = 1, temp = 1;
    int i = 1, ctr = r - 1;

    while (ctr-- >= 0) {
      temp = (temp * num) / dino;
      num--, dino++;
      v[i++] = temp;
    }

    return v;
  }
};