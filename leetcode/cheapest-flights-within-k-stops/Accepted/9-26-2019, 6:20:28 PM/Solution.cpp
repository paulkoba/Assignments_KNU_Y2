// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
    int findCheapestPrice(const int n, 
                          const vector<vector<int>>& flights, const int src, const int dst, const int k) {
        vector<int> costs(n, numeric_limits<int>::max() >> 1);
        
        costs[src] = 0;
        
        for(int i = 0; i <= k; ++i) {
            const vector<int> temp(costs);
            for(const vector<int>& t : flights) {
                costs[t[1]] = min(costs[t[1]], temp[t[0]] + t[2]);
            }
        }
        
        if(costs[dst] == numeric_limits<int>::max() >> 1) return -1;
        
        return costs[dst];
    }
};