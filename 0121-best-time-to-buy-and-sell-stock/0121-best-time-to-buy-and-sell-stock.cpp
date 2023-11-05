class Solution{
public:
    int maxProfit(vector<int> &prices){
        int n = (int)prices.size();

        int maxPro = 0;
        int minPrice = INT_MAX;
        for (int i = 0; i < n; i++){
            minPrice = min(minPrice, prices[i]);
            maxPro = max(maxPro, prices[i] - minPrice);
        }
        return maxPro;
    }
};