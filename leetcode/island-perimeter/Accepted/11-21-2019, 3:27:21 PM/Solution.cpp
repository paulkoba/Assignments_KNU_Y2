// https://leetcode.com/problems/island-perimeter

class Solution {
public:
    int islandPerimeter(const vector<vector<int>>& grid) {
        const size_t height = grid.size();
        if(height == 0) return 0;
        const size_t width = grid[0].size();
        
        int output = accumulate(grid[0].begin(), grid[0].end(), 0) * 2;
        
        for(size_t i = 1; i < height; ++i)
            for(size_t j = 0; j < width; ++j)
                output += 2 * grid[i][j] - (grid[i][j] == grid[i - 1][j] && grid[i][j]);
        
        for(size_t i = 0; i < height; ++i)
            for(size_t j = 1; j < width; ++j)
                output -= grid[i][j] == grid[i][j - 1] && grid[i][j];
        
        return output * 2;
    }
};