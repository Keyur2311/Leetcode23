class Solution{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success){
        int n = spells.size();
        int m = potions.size();

        sort(potions.begin(), potions.end());
        vector<int> pairs(n, 0);

        for (int i = 0; i < n; i++){
            long long a = success, b = spells[i];
            long long x = (a + b - 1) / b;
            auto it = lower_bound(potions.begin(), potions.end(), x) - potions.begin();
            pairs[i] = m - it;
        }
        
        return pairs;
    }
};