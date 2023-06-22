class Solution{
public:
    int maxProfit(vector<int> &prices){
        int n = (int)prices.size();

        int bd = 0, sd = 0, profit = 0;

        for (int i = 1; i < n; i++){
            if (prices[i] >= prices[i - 1])
                sd++;
            else{
                profit += prices[sd] - prices[bd];
                bd = sd = i;
            }
        }
        
        profit += prices[sd] - prices[bd];

        return profit;
    }
};