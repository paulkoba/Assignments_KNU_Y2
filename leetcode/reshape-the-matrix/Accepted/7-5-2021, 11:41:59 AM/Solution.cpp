// https://leetcode.com/problems/reshape-the-matrix

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        
        if(m * n != r * c) return mat;
        
        vector<int> flatten(m * n);
        int idx = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                flatten[idx++] = mat[i][j];
            }
        }
        
        idx = 0;
        
        vector<vector<int>> output(r, vector<int>(c));
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                output[i][j] = flatten[idx++];
            }
        }
        
        return output;
    }
};