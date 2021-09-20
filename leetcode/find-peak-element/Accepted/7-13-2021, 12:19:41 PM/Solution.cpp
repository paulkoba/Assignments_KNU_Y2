// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int sz = nums.size();
        int l = 0;
        int r = sz - 1;
        
        while(l < r) {
            int m = (l + r) / 2;
            
            if(m < sz - 1 && nums[m] < nums[m + 1]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        
        return l;
    }
};