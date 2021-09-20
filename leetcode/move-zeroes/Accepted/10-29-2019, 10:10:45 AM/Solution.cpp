// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastZero = 0;
        int sz = nums.size();
        for(int i = 0; i < sz; ++i) {
            if(nums[i] != 0) swap(nums[i], nums[lastZero++]);
        }
    }
};