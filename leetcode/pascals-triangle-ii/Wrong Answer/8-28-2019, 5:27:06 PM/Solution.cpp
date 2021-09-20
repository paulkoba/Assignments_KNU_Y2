// https://leetcode.com/problems/pascals-triangle-ii

class Solution {
public:
    vector<int> getRow(int numRows) {
        if(numRows == 0) return {};
        
        vector<int> output(numRows);
        for(int i = 1; i <= numRows; i++) {
            vector<int> row(i + 1);
            row[0] = 1;
            for(int j = 1; j < i; j++) {
                row[j] = output[j - 1] + output[j];
            }
            row[i] = 1;
            output = row;
        }
        
        return output;
    }
};