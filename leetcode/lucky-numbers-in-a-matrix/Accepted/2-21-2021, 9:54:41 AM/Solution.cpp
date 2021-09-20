// https://leetcode.com/problems/lucky-numbers-in-a-matrix

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> rows(matrix.size(), numeric_limits<int>::max());
        vector<int> cols(matrix[0].size(), numeric_limits<int>::min());
        
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                rows[i] = min(rows[i], matrix[i][j]);
                cols[j] = max(cols[j], matrix[i][j]);
            }
        }
        
        vector<int> lucky;
        
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                if(rows[i] == matrix[i][j] && cols[j] == matrix[i][j])
                    lucky.push_back(matrix[i][j]);
            }
        }
        
        return lucky;
    }
};