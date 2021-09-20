// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        int current_profit = 0;
        
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i - 1])
                current_profit += prices[i] - prices[i - 1];
        }
        
        return current_profit;
    }
};