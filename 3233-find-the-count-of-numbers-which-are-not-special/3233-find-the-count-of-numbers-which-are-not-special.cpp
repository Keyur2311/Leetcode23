class Solution {
public:
  int nonSpecialCount(int l, int r) {
    long long int N = (long long int)1e5 + 10;
    bool isprime[N + 1];
    for (int i = 2; i <= N; i++)
      isprime[i] = true;

    for (int i = 2; i * i <= N; i++) {
      if (isprime[i] == true) {
        for (int j = i * i; j <= N; j += i)
          isprime[j] = false;
      }
    }

    long long int x = 1;
    int ans = r - l + 1;
    while (x * x <= r) {
      if (x * x >= l && isprime[x])
        ans--;
      x++;
    }
    return ans;
  }
};