// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output = {{1}};
        
        for(int i = 0; i < numRows - 1; ++i) {
            vector<int> nextRow = {1};
            for(int j = 1; j < output[i].size(); ++j) {
                nextRow.push_back(output[i][j] + output[i][j - 1]);
            }
            nextRow.push_back(1);
            
            output.push_back(nextRow);
        }
        
        return output;
    }
};