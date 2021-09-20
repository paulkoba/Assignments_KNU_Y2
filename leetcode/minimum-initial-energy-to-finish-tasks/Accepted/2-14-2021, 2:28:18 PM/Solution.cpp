// https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), 
             [](const vector<int>& a, const vector<int>& b) 
             { return a[1] - a[0] > b[1] - b[0]; });
        
        int minEnergy = tasks[0][1];
        int currentEnergy = tasks[0][1];
        for(const auto& p : tasks) {
            if(currentEnergy < p[1]) {
                minEnergy += p[1] - currentEnergy;
                currentEnergy = p[1];
            }
            
            currentEnergy -= p[0];
        }
        
        return minEnergy;
    }
};