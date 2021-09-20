// https://leetcode.com/problems/matrix-diagonal-sum

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int output = 0;
        for(int i = 0; i < mat.size(); ++i) {
            output += mat[i][i] + mat[i][mat.size() - 1 - i];
        }
        
        if(mat.size() % 2 == 1) output -= mat[mat.size() / 2][mat.size() / 2];
        
        return output;
    }
};