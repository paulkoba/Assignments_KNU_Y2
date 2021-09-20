// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto result = equal_range(nums.begin(), nums.end(), target);
    
        if(result.first == nums.end() || *result.first != target) return {-1, -1};
        
        return {(int)(result.first - nums.begin()), 
                (int)(result.second - nums.begin()) - 1};
    }
};