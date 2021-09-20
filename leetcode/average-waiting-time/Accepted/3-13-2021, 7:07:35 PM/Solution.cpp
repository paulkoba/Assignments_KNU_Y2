// https://leetcode.com/problems/average-waiting-time

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {        
        int64_t n = customers.size();
        
        int64_t output = 0;
        int64_t currentT = 0;
        for(int64_t i = 0; i < n; ++i) {
            if(currentT <= customers[i][0]) {
                currentT = customers[i][0] + customers[i][1];
                output += customers[i][1];
            } else {
                currentT += customers[i][1];
                output += currentT - customers[i][0];
            }
        }
        
        return (double)output / n;
        
    }
};