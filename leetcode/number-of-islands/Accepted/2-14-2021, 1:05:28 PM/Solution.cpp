// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    void bfs(vector<vector<char>>& grid, int a, int b) {
        if(grid.size() <= a || a < 0 || grid[0].size() <= b || b < 0) return;
        
        if(grid[a][b] == '1') {
            grid[a][b] = '2';
            bfs(grid, a - 1, b);
            bfs(grid, a + 1, b);
            bfs(grid, a, b - 1);
            bfs(grid, a, b + 1);
        } 
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == '1') {
                    bfs(grid, i, j);
                    ++count;
                }
            }
        }
        
        return count;
    }
};