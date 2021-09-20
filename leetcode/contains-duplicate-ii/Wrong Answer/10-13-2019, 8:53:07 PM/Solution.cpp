// https://leetcode.com/problems/contains-duplicate-ii

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = nums.size();
        int lastIndex = 0, firstIndex = 0;
        
        while(lastIndex < l) {
            if(lastIndex <= firstIndex) lastIndex++;
            if(nums[lastIndex] - nums[firstIndex++] <= k) return true;
        }
        
        return false;
    }
};