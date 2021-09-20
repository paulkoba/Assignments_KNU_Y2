// https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = 0;
        for(int i : nums) sum += i;
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        size_t idx = 0;
        sum /= 2;
        while(sum >= 0) {
            sum -= nums[idx];
            ++idx;
        }
        return std::vector<int>(nums.begin(), nums.begin() + idx);
    }
};