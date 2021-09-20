// https://leetcode.com/problems/partition-array-into-disjoint-intervals

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        stack<int> minValue;
        int sz = nums.size();
        minValue.push(nums[sz - 1]);
        for(int i = sz - 2; i >= 0; --i) {
            minValue.push(min(minValue.top(), nums[i]));
        }
        int maxValue = nums[0];
        for(int i = 0; i < sz; ++i) {
            minValue.pop();
            maxValue = max(maxValue, nums[i]);
            if(maxValue <= minValue.top()) return i + 1;
        }
        
        return -1;
    }
};