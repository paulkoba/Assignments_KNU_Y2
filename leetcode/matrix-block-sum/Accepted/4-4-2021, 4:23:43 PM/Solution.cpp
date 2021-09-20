// https://leetcode.com/problems/matrix-block-sum

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> sums(m, vector<int>(n, 0));
        
        sums[0][0] = mat[0][0];
        for(int i = 1; i < m; ++i) sums[i][0] = sums[i - 1][0] + mat[i][0];
        for(int i = 1; i < n; ++i) sums[0][i] = sums[0][i - 1] + mat[0][i];
        
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                sums[i][j] = sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1] + mat[i][j];
            }
        }
        
        vector<vector<int>> output(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int idxHI = (i + k >= m) ? m - 1 : i + k;
                int idxLI = i - k - 1;
                int idxHJ = (j + k >= n) ? n - 1 : j + k;
                int idxLJ = j - k - 1;
                
                output[i][j] = sums[idxHI][idxHJ] 
                    - (idxLI >= 0 ? sums[idxLI][idxHJ] : 0) - (idxLJ >= 0 ? sums[idxHI][idxLJ] : 0) 
                    + (idxLI >= 0 && idxLJ >= 0 ? sums[idxLI][idxLJ] : 0);
            }
        }
        
        return output;
    }
};