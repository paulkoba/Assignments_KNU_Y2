// https://leetcode.com/problems/build-array-from-permutation

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> output(nums.size());
        
        for(int i = 0; i < nums.size(); ++i) {
            output[i] = nums[nums[i]];
        }
        
        return output;
    }
};