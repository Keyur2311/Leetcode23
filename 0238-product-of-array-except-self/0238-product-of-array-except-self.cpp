class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = (int)nums.size();
        vector<int> pref(n, 1), suff(n, 1);

        pref[0] = nums[0], suff[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++)
            pref[i] = nums[i] * pref[i - 1];
        for (int i = n - 2; i >= 0; i--)
            suff[i] = nums[i] * suff[i + 1];

        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            int val1 = 1, val2 = 1;
            if (i - 1 >= 0)
                val1 = pref[i - 1];
            if (i + 1 < n)
                val2 = suff[i + 1];

            ans[i] = val1 * val2;
        }

        return ans;
    }
};