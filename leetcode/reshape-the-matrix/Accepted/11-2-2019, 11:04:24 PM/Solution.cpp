// https://leetcode.com/problems/reshape-the-matrix

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int height = nums.size();
        if(height == 0) return nums;
        int width = nums[0].size();
        if(height * width != r * c) return nums;
        
        vector<vector<int>> out(r);
        
        for(int i = 0; i < r; ++i) out[i] = vector<int>(c);
        
        for(int i = 0; i < r * c; ++i) out[i / c][i % c] = nums[i / width][i % width];
        
        return out;
    }
};