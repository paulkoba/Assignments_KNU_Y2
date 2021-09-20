// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(const vector<int>& nums) {
        int length = nums.size();
        int local_max = 0;
        int current = 0;

        if (length == 0) return 0;

        for (int i = 0; i < length; i++) {
            current += nums[i];
            if (current < 0) {
                current = 0;
            }
            else if (current > local_max) {
                local_max = current;
            }
        }

        return local_max;
    }
};