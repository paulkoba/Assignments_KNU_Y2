// https://leetcode.com/problems/average-waiting-time

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {        
        int n = customers.size();
        
        int output = 0;
        int currentT = 0;
        for(int i = 0; i < n; ++i) {
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