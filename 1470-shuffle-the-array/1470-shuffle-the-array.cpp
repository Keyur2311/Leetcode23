class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2 * n);
        int j = 0;
    for (int i = 0; i < 2 * n; i += 2)
        ans[i] = nums[j++];
    for (int i = 1; i < 2 * n; i += 2)
        ans[i] = nums[j++];

    return ans;
    }
};