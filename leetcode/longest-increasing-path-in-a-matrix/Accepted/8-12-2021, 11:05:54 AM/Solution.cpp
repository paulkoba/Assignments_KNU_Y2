// https://leetcode.com/problems/longest-increasing-path-in-a-matrix

class Solution {
public:
    int dfs(vector<vector<int>>& memo, vector<vector<int>>& matrix, int val, int i, int j) {
        if(i < 0 || j < 0) return numeric_limits<int>::min();
        if(i == matrix.size() || j == matrix[0].size()) return numeric_limits<int>::min();
        if(matrix[i][j] <= val) return numeric_limits<int>::min();
        if(memo[i][j] != -1) return memo[i][j];
        
        memo[i][j] = numeric_limits<int>::min();
        
        int m = 1;
        m = max(dfs(memo, matrix, matrix[i][j], i + 1, j) + 1, m);
        m = max(dfs(memo, matrix, matrix[i][j], i - 1, j) + 1, m);
        m = max(dfs(memo, matrix, matrix[i][j], i, j - 1) + 1, m);
        m = max(dfs(memo, matrix, matrix[i][j], i, j + 1) + 1, m);
        return memo[i][j] = m;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> memo(m, vector<int>(n, -1));
        int output = -1;
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(memo[i][j] != -1) continue;
                output = max(dfs(memo, matrix, -100, i, j), output);
            }
        }
        
        return output;
    }
};