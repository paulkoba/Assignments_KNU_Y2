// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int currentEnd = 0;
        
        for(int i = 0; i < nums.size(); ++i) {
            if(currentEnd < i) return false;
            
            currentEnd = max(nums[i] + i, currentEnd);
        }
        
        return true;
    }
};