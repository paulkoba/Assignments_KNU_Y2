// https://leetcode.com/problems/set-matrix-zeroes

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        if(m == 0) return;
        const int n = matrix[0].size();
        
        int rows[m] = {};
        int columns[n] = {};
        
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(!matrix[i][j]) rows[i] = columns[j] = 1;
        
        for(int i = 0; i < m; ++i)
            if(rows[i]) fill(matrix[i].begin(), matrix[i].end(), 0);
        
        for(int i = 0; i < n; ++i)
            if(columns[i])
                for(int j = 0; j < m; ++j) matrix[j][i] = 0;
    }
};