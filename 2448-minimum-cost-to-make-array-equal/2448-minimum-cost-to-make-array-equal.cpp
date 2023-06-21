class Solution
{
public:
    long long minCost(vector<int> &nums, vector<int> &cost)
    {
        int n = (int)nums.size();

        if (n == 1)
            return 0;

        vector<pair<long long int, long long int>> vp(n);
        for (int i = 0; i < n; i++)
            vp[i].first = nums[i], vp[i].second = cost[i];

        sort(vp.begin(), vp.end());

        for (int i = 0; i < n; i++)
            nums[i] = vp[i].first, cost[i] = vp[i].second;

        vector<long long> merge(n);
        for (int i = 0; i < n; i++)
            merge[i] = (long long int)(1LL * nums[i] * cost[i]);

        vector<long long int> mpref(n, 0), cpref(n, 0);
        mpref[0] = merge[0], cpref[0] = cost[0];

        for (int i = 1; i < n; i++)
            mpref[i] = mpref[i - 1] + merge[i];
        for (int i = 1; i < n; i++)
            cpref[i] = cpref[i - 1] + cost[i];

      
        long long int ans = LLONG_MAX;

        for (int i = 0; i < n; i++)
        {
            long long int val = 0;
            if (i == 0)
                val = abs(nums[i] * (cpref[n - 1] - cpref[0]) - (mpref[n - 1] - mpref[0]));
            else if (i == n - 1)
                val = (nums[i] * cpref[n - 2] - mpref[n - 2]);
            else
                val = (nums[i] * cpref[i - 1] - mpref[i - 1]) + abs((nums[i] * (cpref[n - 1] - cpref[i]) - (mpref[n - 1] - mpref[i])));
           
            ans = min(ans, val);
        }

        return ans;
    }
};