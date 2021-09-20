// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        for(int i = 2; i < sz; ++i) {
            nums[i] = max(nums[i - 1], nums[i - 2] + nums[i]);
        }
        return nums[sz - 1];
    }
};