// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        size_t length = nums.size();

        for(int i = 0; i < length; ++i) {
            if(nums[index] != nums[i]) {
                nums[++index] = nums[i];
            }
        }
        
        return index + 1;
    }
};