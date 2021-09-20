// https://leetcode.com/problems/max-increase-to-keep-city-skyline

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        const size_t sz = grid.size();
        if(sz <= 1) return 0;
        
        vector<int> rows(sz);
        vector<int> cols(sz);
        
        for(int i = 0; i < sz; ++i) {
            for(int j = 0; j < sz; ++j) {
                rows[i] = max(rows[i], grid[i][j]);
                cols[j] = max(cols[j], grid[i][j]);
            }
        }
        
        int count = 0;
        for(int i = 0; i < sz; ++i)
            for(int j = 0; j < sz; ++j)
                count += min(rows[i], cols[j]) - grid[i][j];
        
        return count;
    }
};