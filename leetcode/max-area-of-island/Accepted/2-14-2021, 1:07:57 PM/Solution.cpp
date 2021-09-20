// https://leetcode.com/problems/max-area-of-island

class Solution {
public:
    void bfs(vector<vector<int>>& grid, int a, int b, int& count) {
        if(grid.size() <= a || a < 0 || grid[0].size() <= b || b < 0) return;
        
        if(grid[a][b] == 1) {
            grid[a][b] = 2;
            ++count;
            bfs(grid, a - 1, b, count);
            bfs(grid, a + 1, b, count);
            bfs(grid, a, b - 1, count);
            bfs(grid, a, b + 1, count);
        } 
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxCount = 0;
        
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 1) {
                    int count = 0;
                    
                    bfs(grid, i, j, count);
                    
                    maxCount = max(count, maxCount);
                }
            }
        }
        
        return maxCount;
    }
};