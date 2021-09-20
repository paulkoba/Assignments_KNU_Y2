// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> output;
        for(int i = 0; i < prices.size(); ++i) {
            bool flag = true;
            for(int j = i + 1; j < prices.size(); ++j) {
                if(prices[j] <= prices[i]) {
                    output.push_back(prices[i] - prices[j]);
                    flag = false;
                    break;
                }
            }
            if(flag) output.push_back(prices[i]);
        }
        
        return output;
    }
};