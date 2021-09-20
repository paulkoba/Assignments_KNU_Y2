// https://leetcode.com/problems/target-sum

class Solution {
public:
    int findTargetSumWays(const vector<int>& nums, int S) {
        int ways = 0;
        for(int i = 0; i < pow(2, nums.size()); ++i) {
            int sum = 0;
            for(int j = 0; j < nums.size(); ++j) sum += ((i >> j) & 1) ? nums[j] : -nums[j];
            ways += sum == S;
        }
        return ways;
    }
};