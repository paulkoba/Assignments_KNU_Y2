// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int sz = nums.size();
        int first = 0, last = sz - 1;
        
        while(first <= last) {
            int middle = first + (last - first) / 2;
            if(nums[middle] < target) {
                first = middle + 1;
            } else if(nums[middle] > target) {
                last = middle - 1;
            } else return middle;
        }
        
        return first;
    }
};