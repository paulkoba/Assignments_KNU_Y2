// https://leetcode.com/problems/projection-area-of-3d-shapes

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int sz = grid.size();
        int area = 0;
        
        for(int i = 0; i < sz; ++i)
            for(int j = 0; j < sz; ++j)
                area += grid[i][j] > 0;
        
        for(int i = 0; i < sz; ++i) {
            int k = grid[0][i];
            for(int j = 1; j < sz; ++j)
                k = max(k, grid[j][i]);
            area += k;
        }
        
        for(int i = 0; i < sz; ++i) {
            int k = grid[i][0];
            for(int j = 1; j < sz; ++j)
                k = max(k, grid[i][j]);
            area += k;
        }
        
        return area;
    }
};