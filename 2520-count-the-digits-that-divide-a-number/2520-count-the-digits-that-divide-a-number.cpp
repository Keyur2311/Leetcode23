class Solution {
public:
    int countDigits(int num) {
        int val = num;
    int ans = 0;
    while (val > 0)
    {
        int d = val % 10;
        if ((num % d) == 0)
            ans++;
        val = val / 10;
    }

    return ans;
    }
};