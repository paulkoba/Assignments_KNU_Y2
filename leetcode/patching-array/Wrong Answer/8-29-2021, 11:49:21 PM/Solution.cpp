// https://leetcode.com/problems/patching-array

class Solution {
public:
    int minPatches(vector<int>& nums, int64_t n) {
        int64_t last = 0;
        while(last < nums.size() && nums[last] < n) ++last;
        
        int64_t cap = 0;
        int64_t i = 0;
        int64_t output = 0;
        
        while(i < last && cap < n) {
            
            while(nums[i] > cap + 1) {
                ++output;
                
                cap = cap * 2 + 1;
            }
            
            cap += nums[i];
            ++i;
        }
        
        while(cap + 1 < n) {
            ++output;
            cap = cap * 2 + 1;
        }
        
        return output;
    }
};