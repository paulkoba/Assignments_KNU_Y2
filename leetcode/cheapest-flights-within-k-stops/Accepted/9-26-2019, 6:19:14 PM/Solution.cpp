// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> costs(n, numeric_limits<int>::max() >> 1);
        
        costs[src] = 0;
        
        for(int i = 0; i <= k; ++i) {
            vector<int> temp(costs);
            for(const vector<int>& t : flights) {
                costs[t[1]] = min(costs[t[1]], temp[t[0]] + t[2]);
            }
        }
        
        if(costs[dst] == numeric_limits<int>::max() >> 1) return -1;
        
        return costs[dst];
    }
};