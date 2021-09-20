// https://leetcode.com/problems/maximum-average-subarray-i

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sz = nums.size();
        int sum = accumulate(nums.begin(), nums.begin() + k, 0);
        int maxSum = sum;
        for(int i = k; i < sz; ++i) {
            sum += nums[i] - nums[i - k];
            maxSum = max(maxSum, sum);
        }
        return (double)maxSum / k;
    }
};