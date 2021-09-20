// https://leetcode.com/problems/two-city-scheduling

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        const int full_length = costs.size();
        const int length = full_length / 2;
        
        sort(costs.begin(), costs.end(),
             [] (vector<int>& a, vector<int>& b) {
                 return (a[1] - a[0]) > (b[1] - b[0]); });
        
        int cost = 0;
        int index = 0;
        
        while(index < length)
            cost += costs[index++][0];
        
        while(index < full_length) 
            cost += costs[index++][1];
        
        return cost;
    }
};