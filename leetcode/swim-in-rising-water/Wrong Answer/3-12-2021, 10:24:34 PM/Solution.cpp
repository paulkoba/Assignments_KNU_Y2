// https://leetcode.com/problems/swim-in-rising-water

class Solution {
public:
    
    void dfs(vector<vector<int>>& status, int x, int y, int val) {
        if(x < 0 || y < 0 || x == status.size() || y == status.size()) return;
        if(status[x][y] != 1) return;
        status[x][y] = val;
        dfs(status, x - 1, y, val);
        dfs(status, x + 1, y, val);
        dfs(status, x, y - 1, val);
        dfs(status, x, y + 1, val);
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> status(n, vector<int>(n, 0)); 
        //0 - not visited yet, 1 - visited, cant reach both ends, 2 - visited, start reachable, 3 - end reachable.
        status[0][0] = 2;
        status[n - 1][n - 1] = 3;
        
        int t = 1;
        
        unordered_map<int, pair<int, int>> positions;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                positions[grid[i][j]] = {i, j};
            }
        }
        
        while(true) {
            if(!status[positions[t].first][positions[t].second]) status[positions[t].first][positions[t].second] = 1;
            
            bool has2 = (positions[t].first ? status[positions[t].first - 1][positions[t].second] == 2 : 0 ) ||
                (positions[t].second ? status[positions[t].first][positions[t].second - 1] == 2 : 0 ) ||
              (positions[t].second < n - 1 ? status[positions[t].first][positions[t].second + 1] == 2 : 0 ) ||
                (positions[t].first < n - 1 ? status[positions[t].first + 1][positions[t].second] == 2 : 0 );
            
            bool has3 = (positions[t].first ? status[positions[t].first - 1][positions[t].second] == 3 : 0 ) ||
                (positions[t].second ? status[positions[t].first][positions[t].second - 1] == 3 : 0 ) ||
              (positions[t].second < n - 1 ? status[positions[t].first][positions[t].second + 1] == 3 : 0 ) ||
                (positions[t].first < n - 1 ? status[positions[t].first + 1][positions[t].second] == 3 : 0 );
            
            if(has2 && has3) return max(max(t, grid[n - 1][n - 1]), grid[0][0]);
            if(has2 || has3) dfs(status, positions[t].first, positions[t].second, has2 ? 2 : 3);
            
            ++t;
        }
        
        return -1;
    }
};