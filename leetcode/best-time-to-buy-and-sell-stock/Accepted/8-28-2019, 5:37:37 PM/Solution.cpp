// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        int current_max_profit = 0;
        int min = numeric_limits<int>::max();
        for(int i = 0; i < prices.size(); i++) {
            if(min > prices[i]) {
                min = prices[i];
            } else if(prices[i] - min > current_max_profit) {
                current_max_profit = prices[i] - min;
            }
        }
        return current_max_profit;
    }
};