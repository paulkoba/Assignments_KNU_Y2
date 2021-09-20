// https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing

class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        int count = 0;
        int sz = nums.size();
        
        for(int i = 1; i < sz; ++i) {
            if(nums[i] > nums[i - 1]) continue;
            count += nums[i - 1] - nums[i] + 1;
            nums[i] = nums[i - 1] + 1;
        }
        
        return count;
    }
};