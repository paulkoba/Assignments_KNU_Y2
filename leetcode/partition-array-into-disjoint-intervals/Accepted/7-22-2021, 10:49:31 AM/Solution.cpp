// https://leetcode.com/problems/partition-array-into-disjoint-intervals

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        vector<int> minValue(nums.size());
        int sz = nums.size();
        minValue[sz - 1] = nums[sz - 1];
        for(int i = sz - 2; i >= 0; --i) {
            minValue[i] = min(minValue[i + 1], nums[i]);
        }
        int maxValue = nums[0];
        for(int i = 0; i < sz; ++i) {
            maxValue = max(maxValue, nums[i]);
            if(maxValue <= minValue[i + 1]) return i + 1;
        }
        
        return -1;
    }
};