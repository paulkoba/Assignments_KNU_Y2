// https://leetcode.com/problems/binary-search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first = 0, last = nums.size() - 1;
        
        while(first <= last) {
            int middle = (first + last) / 2;
            if(nums[middle] < target) {
                first = middle + 1;
            } else if(nums[middle] > target) {
                last = middle - 1;
            } else return middle;
        }
        
        return -1;
    }
};