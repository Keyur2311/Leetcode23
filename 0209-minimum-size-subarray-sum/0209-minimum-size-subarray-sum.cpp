class Solution{
public:
    int minSubArrayLen(int target, vector<int> &nums){
        int n = (int)nums.size();
        int i = 0, j = 0;

        int ans = n+1, sum = 0;
        while (j < n) {
            sum += nums[j];

            while (i < n && i <= j && sum >= target){
                ans = min(ans, j - i + 1);
                sum -= nums[i++];
            }

            j++;
        }

        if (sum >= target)
            ans = min(ans, j - i + 1);

        return ans == n+1 ? 0 : ans;
    }
};