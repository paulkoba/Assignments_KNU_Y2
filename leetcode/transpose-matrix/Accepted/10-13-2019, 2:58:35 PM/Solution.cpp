// https://leetcode.com/problems/transpose-matrix

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        
        vector<vector<int>> output(n);
        
        for(int i = 0; i < n; ++i) {
            output[i] = vector<int>(m);
            
            for(int j = 0; j < m; ++j) {
                output[i][j] = A[j][i];
            }
        }
        
        return output;
    }
};