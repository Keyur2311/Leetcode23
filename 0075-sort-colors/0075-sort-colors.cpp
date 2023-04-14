class Solution{
public:
    void sortColors(vector<int> &nums){
        int count0 = 0, count1 = 0, count2 = 0;
        for (auto &it : nums)
        {
            count0 += (it == 0);
            count1 += (it == 1);
            count2 += (it == 2);
        }

        for (auto &it : nums)
        {
            if (count0 > 0)
            {
                it = 0;
                count0--;
            }
            else if (count1 > 0)
            {
                it = 1;
                count1--;
            }
            else
            {
                it = 2;
                count2--;
            }
        }
    }
};