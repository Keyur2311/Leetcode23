class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int buy1 = INT_MIN, sale1 = 0, buy2 = INT_MIN, sale2 = 0;
    for (int i = 0; i < prices.size();i++) { 
      buy1 = max(buy1, -prices[i]);         
      sale1 = max(sale1, prices[i] + buy1); 
      buy2 = max(buy2, sale1 - prices[i]);  
      sale2 = max(sale2, prices[i] + buy2); 
    }
    return sale2;
  }
};