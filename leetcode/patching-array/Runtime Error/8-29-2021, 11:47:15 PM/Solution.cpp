// https://leetcode.com/problems/patching-array

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int64_t last = 0;
        while(last < nums.size() && nums[last] < n) ++last;
        
        int cap = 0;
        int i = 0;
        int output = 0;
        
        while(i < last && cap < n) {
            
            while(nums[i] > cap + 1) {
                ++output;
                
                cap = cap * 2 + 1;
            }
            
            cap += nums[i];
            ++i;
        }
        
        while(cap < n) {
            ++output;
            cap = cap * 2 + 1;
        }
        
        return output;
    }
};