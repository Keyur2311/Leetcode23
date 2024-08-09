class Solution {
public:
  int countPrimes(int n) {
    int N = n + 5;
    bool isprime[N + 1];

    for (int i = 2; i <= N; i++)
      isprime[i] = true;

    int ans = 0;
    for (int i = 2; i * i <= N; i++) {
      if (isprime[i] == true) {
        for (int j = i * i; j <= N; j += i)
          isprime[j] = false;
      }
    }

    for (int i = 2; i < n; i++)
      ans += (isprime[i]);
    return ans;
  }
};