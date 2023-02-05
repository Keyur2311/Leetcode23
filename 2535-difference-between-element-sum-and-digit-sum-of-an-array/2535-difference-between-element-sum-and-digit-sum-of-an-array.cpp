class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum = 0, dsum = 0;
    for (auto &x : nums)
        sum += x;

    for (auto &x : nums)
    {
        while (x > 0)
        {
            dsum += (x % 10);
            x = x / 10;
        }
    }

    return abs(sum - dsum);

    }
};