class Solution {
public:
    int jump(vector<int>& nums) {
        
    int n = (int)nums.size();
    vector<int> temp(n, 100000);
    temp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 1; j <= nums[i] && i + j < n; j++)
            temp[i] = min(temp[i], temp[i + j] + 1);
    }

    return temp[0];
    }
};