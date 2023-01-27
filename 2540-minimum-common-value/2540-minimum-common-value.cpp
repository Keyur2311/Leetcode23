class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
       for (auto &x : nums1)
    {
        int lo = 0, hi = (int)nums2.size() - 1;
        int ans = INT_MAX;
        while (hi >= lo)
        {
            int mid = lo + (hi - lo) / 2;
            if (nums2[mid] == x)
            {
                ans = x;
                return ans;
            }
            else if (nums2[mid] > x)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        if (ans != INT_MAX)
            return ans;
    }
    return -1;
    }
};