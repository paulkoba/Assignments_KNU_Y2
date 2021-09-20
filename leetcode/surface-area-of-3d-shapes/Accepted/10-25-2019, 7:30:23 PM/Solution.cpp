// https://leetcode.com/problems/surface-area-of-3d-shapes

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        int surface = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] != 0) surface += 2;
                if(i != 0) {
                    surface += max(0, grid[i][j] - grid[i - 1][j]);
                } else surface += grid[i][j];
                if(j != 0) {
                    surface += max(0, grid[i][j] - grid[i][j - 1]);
                } else surface += grid[i][j];
                if(i != n - 1) {
                    surface += max(0, grid[i][j] - grid[i + 1][j]);
                } else surface += grid[i][j];
                if(j != n - 1) {
                    surface += max(0, grid[i][j] - grid[i][j + 1]);
                } else surface += grid[i][j];
            }
        }
        return surface;
    }
};