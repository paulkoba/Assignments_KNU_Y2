// https://leetcode.com/problems/single-number

class Solution {
public:
    int singleNumber(const vector<int>& nums) {
        int output = 0;
        for(int i : nums) { output ^= i; }
        return output;
    }
};