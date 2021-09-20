// https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        if(nums.size() < 3) return false;
        bool removed = false;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] <= nums[i - 1]) {
                if(removed == true) return false;
                removed = true;
            }
            
            if(i >= 2 && nums[i] <= nums[i - 2]) {
                if(removed == true) return false;
            }
        }
        
        return true;
    }
};