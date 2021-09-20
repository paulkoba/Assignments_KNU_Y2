// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0) return {};
        
        vector<vector<int>> output(numRows);
        output[0] = {1};
        for(int i = 1; i < numRows; i++) {
            vector<int> row(i + 1);
            row[0] = 1;
            for(int j = 1; j < i; j++) {
                row[j] = output[i - 1][j - 1] + output[i - 1][j];
            }
            row[i] = 1;
            output[i] = row;
        }
        
        return output;
    }
};