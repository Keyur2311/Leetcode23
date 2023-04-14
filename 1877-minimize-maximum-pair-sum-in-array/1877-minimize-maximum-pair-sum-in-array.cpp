class Solution{
public:
    int minPairSum(vector<int> &nums){
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());

        int val = 0;
        int i = 0, j = n - 1;
        while (i < j)
        {
            val = max(val, nums[i] + nums[j]);
            i++, j--;
        }
        return val;
    }
};