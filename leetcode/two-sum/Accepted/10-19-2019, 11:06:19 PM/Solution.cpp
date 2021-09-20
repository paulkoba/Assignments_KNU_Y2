// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        unordered_map<int, int> idx;
        int i = 0;
        while(true) {
            if(idx[target - nums[i]] == 0) {
                idx[nums[i]] = i + 1;
            } else {
                return {idx[target - nums[i]] - 1, i};
            }
            ++i;
        }
    }
};