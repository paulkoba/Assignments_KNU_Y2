// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(const vector<int>& nums) {
        int length = nums.size();

        if (length == 0) return 0;

        int current = nums[0];
        int local_max = nums[0];

        for (int i = 0; i < length; i++) {
            current = max(nums[i], current + nums[i]);
            local_max = max(current, local_max);
        }

        return local_max;
    }
};