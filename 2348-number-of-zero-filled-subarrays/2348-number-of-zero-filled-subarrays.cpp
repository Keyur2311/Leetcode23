class Solution {
public:
    long long zeroFilledSubarray(vector<int> &v)
    {
        int n = (int)v.size();
        int i = 0, j = 0;
        long long ans = 0, len = 0;
        while (j < n)
        {
            if (v[j] != 0)
            {
                len = j - i;
                ans += ((len * (len + 1)) / 2);
                ++j;
                i = j;
            }
            else
                j++;
        }

        len = j - i;
        ans += ((len * (len + 1)) / 2);
        return ans;
    }
};