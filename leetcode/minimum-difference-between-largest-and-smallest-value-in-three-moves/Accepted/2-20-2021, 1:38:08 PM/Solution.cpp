// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves

class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4) return 0;
        sort(nums.begin(), nums.end());
        
        return min(min(nums[nums.size() - 4] - nums[0], nums[nums.size() - 3] - nums[1]),
                  min(nums[nums.size() - 2] - nums[2], nums[nums.size() - 1] - nums[3]));
    }
};