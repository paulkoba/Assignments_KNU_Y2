// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int sz = coins.size();
        if(sz == 0) return 0;
        vector<int64_t> costs(amount + 1);
        costs[0] = 0;
        for(int i = 1; i <= amount; ++i) {
            costs[i] = numeric_limits<int32_t>::max();
            for(int j = 0; j < sz; ++j) {
                if(i - coins[j] >= 0)
                    costs[i] = min(costs[i - coins[j]] + 1, costs[i]);
            }
        }
        for(int i : costs) cout << i << " ";
        return costs[amount] >= numeric_limits<int32_t>::max() ? -1 : costs[amount];
    }
};