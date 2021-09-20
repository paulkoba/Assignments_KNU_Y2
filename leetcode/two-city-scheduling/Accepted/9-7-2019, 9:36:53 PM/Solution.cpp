// https://leetcode.com/problems/two-city-scheduling

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int length = costs.size();
         
        sort(costs.begin(), costs.end(),
             [] (vector<int> a, vector<int> b) {
                 return (a[1] - a[0]) > (b[1] - b[0]); });
        
        int cost = 0;
        
        for(int i = 0; i < length / 2; ++i) {
            cost += costs[i][0];
            cost += costs[length - i - 1][1];
        }
        
        return cost;
    }
};