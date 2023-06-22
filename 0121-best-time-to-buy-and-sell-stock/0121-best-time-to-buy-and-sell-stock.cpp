class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = (int)prices.size();

        vector<int> l(n), r(n);
        l[0] = prices[0], r[n - 1] = prices[n - 1];

        for (int i = 1; i < n; i++)
            l[i] = min(prices[i], l[i - 1]);
        for (int i = n - 2; i >= 0; i--)
            r[i] = max(prices[i], r[i + 1]);

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, r[i] - l[i]);

        return ans;
    }
};