class Solution {
public:
   int numberOfSubarrays(vector<int>& A, int k) {
        int res = 0, i = 0, count = 0, n = A.size();
        for (int j = 0; j < n; j++) {
            if (A[j] & 1)
                --k, count = 0;
            while (k == 0)
                k += A[i++] & 1, ++count;
            res += count;
        }
        return res;
    }
};