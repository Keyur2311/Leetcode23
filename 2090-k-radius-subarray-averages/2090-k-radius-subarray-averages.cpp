class Solution{
public:
    vector<int> getAverages(vector<int> &nums, int k){
        
        if(k==0) return nums;
        
        int n = (int)nums.size();
        vector<long long int> pref(n, 0);
        pref[0] = nums[0];

        for (int i = 1; i < n; i++)
            pref[i] = pref[i - 1] + nums[i];

        vector<int> avg(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (i - k < 0 || i + k > n - 1)
                continue;
            long long int val = nums[i];
            int x1 = i - k, y1 = i - 1;
            if (x1 == 0)
                val += pref[y1];
            else
                val += (pref[y1] - pref[x1 - 1]);

            int x2 = i + 1, y2 = i + k;
            val += (pref[y2] - pref[x2 - 1]);
            
            int len = 2 * k + 1;
            val = val / len;
            val=(int)val;
            avg[i] = val;
        }

        return avg;
    }
};