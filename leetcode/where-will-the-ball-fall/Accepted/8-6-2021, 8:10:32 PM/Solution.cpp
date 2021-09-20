// https://leetcode.com/problems/where-will-the-ball-fall

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> output;
        for(int j = 0; j < grid[0].size(); ++j) {
            int currentLocation = j;
            bool stuck = false;
            for(int i = 0; i < grid.size(); ++i) {
                if(grid[i][currentLocation] == -1 && !currentLocation) {
                    stuck = true;
                    break;
                }
                
                if(grid[i][currentLocation] == 1 && currentLocation == grid[0].size() - 1) {
                    stuck = true;
                    break;
                }
                
                if(grid[i][currentLocation] == 1 && grid[i][currentLocation + 1] == -1) {
                    stuck = true;
                    break;
                }
                
                if(grid[i][currentLocation] == -1 && grid[i][currentLocation - 1] == 1) {
                    stuck = true;
                    break;
                }
                
                if(grid[i][currentLocation] == 1) {
                    ++currentLocation;
                } else {
                    --currentLocation;
                }
            }
            
            if(!stuck) {
                output.push_back(currentLocation);
            } else {
                output.push_back(-1);
            }
        }
        
        return output;
    }
};