// https://leetcode.com/problems/making-a-large-island

class Solution {
private:
    int index = 2;
public:
    int dp(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size()) return 0;
        if(j < 0 || j >= grid.size()) return 0;
        if(grid[i][j] == 0) return 0;
        if(grid[i][j] != 1) return 0;
        grid[i][j] = index;
        return dp(grid, i - 1, j) +
            dp(grid, i, j - 1) + 
            dp(grid, i + 1, j) + 
            dp(grid, i, j + 1) + 1;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int sz = grid.size();
        index = 2;
        unordered_map<int, int> islandIndexToSize;
        for(int i = 0; i < sz; ++i) {
            for(int j = 0; j < sz; ++j) {
                int result = dp(grid, i, j);
                islandIndexToSize[index] = result;
                ++index;
            }
        }
        
        int output = 0;
        for(const auto& it : islandIndexToSize) output = max(output, it.second);

        for(int i = 0; i < sz; ++i) {
            for(int j = 0; j < sz; ++j) {
                if(grid[i][j] != 0) continue;
                set<int> uniqueNeighboring;
                if(i) uniqueNeighboring.insert(grid[i - 1][j]);
                if(j) uniqueNeighboring.insert(grid[i][j - 1]);
                if(i < sz - 1) uniqueNeighboring.insert(grid[i + 1][j]);
                if(j < sz - 1) uniqueNeighboring.insert(grid[i][j + 1]);
                
                int currentMergedIslandSize = 1;
                
                for(int el : uniqueNeighboring) {
                    currentMergedIslandSize += islandIndexToSize[el];
                }
                
                output = max(output, currentMergedIslandSize);
            }
        }
        
        return output;
    }
};