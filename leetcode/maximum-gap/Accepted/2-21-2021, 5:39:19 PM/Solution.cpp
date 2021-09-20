// https://leetcode.com/problems/maximum-gap

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() < 2) return 0;
        int output = 0;
        for(int i = 1; i < nums.size(); ++i) {
            output = max(output, nums[i] - nums[i - 1]);
        }
        return output;
    }
};