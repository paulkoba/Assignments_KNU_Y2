// https://leetcode.com/problems/reshape-the-matrix

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int width = nums[0].size();
        int t = width * nums.size();
        if(t != r * c) return nums;
        
        vector<vector<int>> out(r, vector<int>(c));        
        for(int i = 0; i < t; ++i) out[i / c][i % c] = nums[i / width][i % width];
        
        return out;
    }
};