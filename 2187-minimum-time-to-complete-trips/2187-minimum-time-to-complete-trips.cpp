class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
           auto ok = [&](long long val)
           {
        long long ctr = 0;
        for (auto &x : time)
            ctr += (long long)(val /(long long) x);

        return (ctr >= totalTrips);
            };

    long long l = 1LL;
    long long r = (long long)1e14;
    long long mid, ans = (long long)1e14;

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