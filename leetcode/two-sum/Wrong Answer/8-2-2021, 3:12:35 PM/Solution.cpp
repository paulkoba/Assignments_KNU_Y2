// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> valueToIndex;
        for(int i = 0; i < nums.size(); ++i)
            valueToIndex[nums[i]] = i;
        
        for(int i = 0; i < nums.size(); ++i) {
            if(valueToIndex.find(target - nums[i]) != valueToIndex.end()) {
                return {i, valueToIndex[target - nums[i]]};
            }
        }
        
        return {};
    }
};