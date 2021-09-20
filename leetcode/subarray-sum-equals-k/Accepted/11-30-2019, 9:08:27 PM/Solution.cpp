// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        size_t sz = nums.size();
        unordered_map<int, int> sums;
        
        sums[0] = 1;
        int count = 0;
        
        for(int i = 0; i < sz; ++i) {
            sum += nums[i];
            count += sums[sum - k];
            ++sums[sum];
        }
        
        return count;
    }
};