// https://leetcode.com/problems/missing-number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int out = 0, sz = nums.size();
        for(int i = 0; i < sz; ++i) {
            out += nums[i] - i;
        }
        return sz - out;
    }
};