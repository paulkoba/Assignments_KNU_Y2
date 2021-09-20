// https://leetcode.com/problems/triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        size_t length = triangle.size();

        for(int i = 1; i < length; ++i) {
            triangle[i][0] += triangle[i - 1][0];
            for(int j = 1; j < i; ++j) {
                triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
            }
            triangle[i][i] += triangle[i - 1][i - 1];
        }
        
        int output = numeric_limits<int>::max();
        
        for(int a : triangle[length - 1]) {
            output = min(a, output);
        }
        
        return output;
    }
};