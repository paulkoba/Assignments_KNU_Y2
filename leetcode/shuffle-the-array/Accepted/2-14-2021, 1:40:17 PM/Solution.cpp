// https://leetcode.com/problems/shuffle-the-array

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> output(n * 2, 0);
        
        for(int i = 0; i < n; ++i) {
            output[2 * i] = nums[i];
            output[2 * i + 1] = nums[i + n];
        }
        
        return output;
    }
};