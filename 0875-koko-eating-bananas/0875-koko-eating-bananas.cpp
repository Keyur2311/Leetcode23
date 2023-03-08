class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int hr) {
        auto ok = [&](int val)
    {
        long long ctr = 0;
        for (auto &x : piles)
            ctr += (long long)((x + val - 1) / val);
        return (ctr <= hr);
    };

    long long l = 1;
    long long r = 1e9;
    long long mid, ans = 1e9;

    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (ok(mid))
        {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    return ans;
    }
};


