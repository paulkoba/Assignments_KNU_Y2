// https://leetcode.com/problems/island-perimeter

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int output = 0;
        
        size_t height = grid.size();
        if(height == 0) return 0;
        size_t width = grid[0].size();
        if(width == 0) return 0;
        
        if(height == 1) {
            for(size_t i = 0; i < width; ++i) output += grid[0][i];
            return output * 2 + 2;
        }
        
        if(width == 1) {
            for(size_t i = 0; i < height; ++i) output += grid[i][0];
            return output * 2 + 2;
        }
        
        for(size_t i = 1; i < height; ++i)
            for(size_t j = 0; j < width; ++j) output += grid[i][j] != grid[i - 1][j];
        
        for(size_t j = 1; j < width; ++j)
            for(size_t i = 0; i < height; ++i) output += grid[i][j] != grid[i][j - 1];
        
        for(size_t i = 0; i < height; ++i) output += grid[i][0] + grid[i][width - 1];
        for(size_t i = 0; i < width; ++i) output += grid[0][i] + grid[height - 1][i];
        
        return output;
    }
};