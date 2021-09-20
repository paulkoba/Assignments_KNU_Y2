// https://leetcode.com/problems/special-positions-in-a-binary-matrix

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> rows(mat.size(), 0);
        vector<int> cols(mat[0].size(), 0);
        
        for(int i = 0; i < mat.size(); ++i) {
            for(int j = 0; j < mat[0].size(); ++j) {
                rows[i] += mat[i][j];
                cols[j] += mat[i][j];
            }
        }
        
        int count = 0;
        
        for(int i = 0; i < mat.size(); ++i) {
            for(int j = 0; j < mat[0].size(); ++j) {
                count += mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1;
            }
        }
        
        return count;
    }
};