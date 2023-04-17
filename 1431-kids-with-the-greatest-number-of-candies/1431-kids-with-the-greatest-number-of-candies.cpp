class Solution{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies){
        int n = (int)candies.size();
        vector<bool> result(n, false);

        int mx = -1;
        for (auto &it : candies)
            mx = max(mx, it);

        for (int i = 0; i < n; i++){
            if (candies[i] + extraCandies >= mx)
                result[i] = true;
        }
        return result;
    }
};