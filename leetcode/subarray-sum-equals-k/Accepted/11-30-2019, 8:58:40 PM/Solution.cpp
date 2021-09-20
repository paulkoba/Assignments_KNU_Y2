// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        size_t sz = nums.size();
        vector<int> sums(sz + 1);
        sums[0] = 0;
        for(int i = 1; i <= sz; ++i) sums[i] = sums[i - 1] + nums[i - 1];
        int count = 0;
        for(int i = 0; i <= sz; ++i)
            for(int j = 0; j < i; ++j)
                if((sums[i] - sums[j]) == k) ++count;
            
        return count;
    }
};