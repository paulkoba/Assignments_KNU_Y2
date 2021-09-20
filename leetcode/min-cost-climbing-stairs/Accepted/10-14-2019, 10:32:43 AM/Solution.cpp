// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int sz = cost.size();
        
        vector<int> costMin(sz);
        costMin[sz - 1] = cost[sz - 1];
        costMin[sz - 2] = cost[sz - 2];
        for(int i = sz - 3; i >= 0; --i) {
            costMin[i] = min(costMin[i + 1], costMin[i + 2]) + cost[i];
        }
        
        return min(costMin[0], costMin[1]);
    }
};