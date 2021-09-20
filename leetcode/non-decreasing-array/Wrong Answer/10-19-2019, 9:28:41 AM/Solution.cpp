// https://leetcode.com/problems/non-decreasing-array

class Solution {
public:
    bool checkPossibility(const vector<int>& nums) {
        bool modified = false;
        int sz = nums.size();
        for(int i = 0; i < sz - 1; ++i) {
            if(nums[i] > nums[i + 1]) {
                if(modified) return false;
                modified = true;
            }
        }
            
        return true;
    }
};